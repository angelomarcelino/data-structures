#include "ServoMotor.h" 



ServoMotor::ServoMotor(){
 
}

int* ServoMotor::acelera(int acelerador){
   if (acelerador+paradoDireito < 180) mDireito.write(paradoDireito+acelerador);
   if (acelerador+paradoDireito > 0) mEsquerdo.write(paradoEsquerdo-acelerador);
   int mdir = paradoDireito+acelerador;
   int mesq = paradoEsquerdo-acelerador;
   int *ret = new int[2];
   ret[0]= mdir; ret[1] = mesq;
   return ret;
}

void ServoMotor::setup(int pinEsquerda,int pinDireita){
    paradoDireito = 90; 
    paradoEsquerdo = 90;
    intensidade = 40; 
    mDireito.attach(pinDireita);
    mEsquerdo.attach(pinEsquerda);  


} 

void ServoMotor::calibra(int pEsq, int pDir){
    paradoDireito = pDir; 
    paradoEsquerdo = pEsq;
}

void ServoMotor::frente(){
    mDireito.write(paradoDireito+intensidade); 
    mEsquerdo.write(paradoEsquerdo-intensidade); 
} 

void ServoMotor::viraDireita(){
    mDireito.write(paradoDireito-intensidade); 
    mEsquerdo.write(paradoEsquerdo-intensidade); 
} 

void ServoMotor::viraEsquerda(){
    mDireito.write(paradoDireito+intensidade); 
    mEsquerdo.write(paradoEsquerdo+intensidade); 

} 

void ServoMotor::re(){
    mDireito.write(paradoDireito-intensidade); 
    mEsquerdo.write(paradoEsquerdo+intensidade); 
} 

void ServoMotor::parado(){
    mDireito.write(paradoDireito); 
    mEsquerdo.write(paradoEsquerdo); 
}
