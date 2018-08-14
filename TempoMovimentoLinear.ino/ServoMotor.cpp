#include "ServoMotor.h" 



ServoMotor::ServoMotor(){
 
}

int* ServoMotor::acelera(int acelerador){
   int *ret = new int[2];
   int mdir = paradoDireito+acelerador;
   int mesq = paradoEsquerdo-acelerador;
   if (mdir > 180) mdir = 180; 
   if (mesq < 0) mesq = 0;
   mDireito.write(mdir);
   mEsquerdo.write(mesq);
   ret[0]= mesq;
   ret[1] = mdir;
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
