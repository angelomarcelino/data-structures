#include "ServoMotor.h" 



ServoMotor::ServoMotor(){
 
}

int* ServoMotor::acelera(int acelerador){
   int *ret = new int[2];
   int mdir = paradoDireito+acelerador;
   int mesq = paradoEsquerdo+5-acelerador;
   if (mdir <= 180){
      mDireito.write(mdir);
      ret[1] = mdir;
   }
   else {
      mdir = 180;
      mDireito.write(mdir);
      ret[1] = mdir;
   }
   if (mesq > 0) {
      mEsquerdo.write(mesq);
      ret[0]= mesq; 
   }
   else {
      mesq = 0;
      mEsquerdo.write(mesq);
      ret[0]= mesq;
   }
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
