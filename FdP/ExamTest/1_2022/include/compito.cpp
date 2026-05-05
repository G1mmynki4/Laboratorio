#include "compito.h"

int Memory::getTypeInt(char type){
    switch (type){
        case 'G':
            return 0;
            break;
        case 'C':
            return 1;
            break;
        case 'S':
            return 2;
            break;
        case 'P':
            return 3;
            break;
        case 'T':
            return 4;
            break;
        default:
            return -1;
    }
}

const char* Memory::getTypeStr(int type){
    switch (type)
    {
    case 0:
        return "Gatto: ";
        break;
    case 1:
        return "Cane: ";
        break;
    case 2:
        return "Serpente: ";
        break;
    case 3:
        return "Pavone: ";
        break;
    default:
        return "Tigre: ";
    }
}

void Memory::rotate90(){
    char original[dim * dim];

    for (int i = 0; i < dim * dim; ++i)
        original[i] = matrix[i];
    
    for (int i = 0; i < dim; ++i)
        for (int j = 0; j < dim; ++j)
            matrix[(j + 1) * dim - i - 1] = original[i * dim + j];
}

//Prima parte
Memory::Memory(int d){

    if(d<=0)
        d = 3;
    
    matrix = new char[d*d];
    score = 0;
    dim = d;

    for (int i = 0; i < dim*dim; ++i)
        matrix[i] = '-';
}

Memory::~Memory(){
    delete[] matrix;
}

ostream& operator<<(ostream& os, const Memory &m){
    for (int i = 0; i < m.dim; ++i){
        for (int j = 0; j < m.dim; ++j)
            os << m.matrix[i * m.dim + j]<<" ";
        os << endl;
    }
    os << endl;

    os << "Punteggio: " << m.score << endl;
    return os;
}

void Memory::inserisci(char p, int row1, int col1, int row2, int col2){
    if(p!='T' && p!='P' && p!='G' && p!='C' && p!='S')
        return;
    if(row1<0 || row1 > dim || col1<0 || col1 > dim)
        return;
    if(row2<0 || row2 > dim || col2<0 || col2 > dim)
        return;
    
    if(row1==row2 && col1==col2)
        return;
    
    if(matrix[row1*dim+col1] == '-' && matrix[row2*dim+col2] == '-'){
        matrix[row1 * dim + col1] = p;
        matrix[row2 * dim + col2] = p;
    }else
        return;
}

void Memory::riassumi(){
    int typeArray[5];
    bool noPairs = true;

    for (int i = 0; i < 5; ++i)
        typeArray[i] = 0;

    for (int i = 0; i < dim * dim; ++i)
        if(matrix[i] != '-' && getTypeInt(matrix[i])>=0){
            ++typeArray[getTypeInt(matrix[i])];
        }

    for (int i = 0; i < 5; ++i)
        if(typeArray[i] > 1){
            noPairs = false;
            break;
        }

    if(noPairs){
        cout << "VITTORIA!" << endl;
        return;
    }
    for (int i = 0; i < 5; ++i)
        cout << getTypeStr(i) << (typeArray[i] / 2) << endl;
}

bool Memory::flip(int row1, int col1, int row2, int col2){
    if(row1<0 || row1 > dim || col1<0 || col1 > dim)
        return false;
    if(row2<0 || row2 > dim || col2<0 || col2 > dim)
        return false;
    
    if(row1==row2 && col1==col2)
        return false;

    if(matrix[row1*dim + col1] != '-' && matrix[row2*dim + col2] != '-'){

        if(matrix[row1*dim + col1] == matrix[row2*dim + col2]){
            matrix[row1 * dim + col1] = matrix[row2 * dim + col2] = '-';
            ++score;
            return true;
        }else
            --score;
        return false;
    }

    return false;
}

//Seconda parte
Memory::Memory(const Memory& m){
    score = 0;
    dim = m.dim;

    matrix = new char[dim * dim];
    for (int i = 0; i < dim * dim; ++i)
        matrix[i] = m.matrix[i];
}

Memory Memory::operator+(const Memory& m){
    Memory m1(*this);

    int dim2;
    if(m1.dim > dim)
        dim2 = dim;
    else
        dim2 = m1.dim;

    int m1_dim = m1.dim - dim2;
    int m_dim = m.dim - dim2;

    for (int i = 0; i < dim; ++i)
        for (int j = 0; j < dim; ++j)
            if(m1.matrix[i *dim + m1_dim + j] == '-')
                m1.matrix[i * dim + m1_dim + j] = m.matrix[i * m.dim + m_dim + j];

    return m1;
}

Memory& Memory::operator>>(int angolo){
    angolo %= 4;

    if(angolo < 0)
        angolo += 4;

    for (int a = 0; a < angolo; ++a)
        rotate90();

    return *this;
}