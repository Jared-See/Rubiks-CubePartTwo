#include <Arduino.h>
using namespace std;




void setup() { //The Setup
  Serial.begin(9600);
}





class cubeFace{ //A class of  individual cube faces
public:
  char face[3][3];
  char FC4 = face[2][0];
  char Fe3 = face[2][1];
  char FC3 = face[2][2];
  char Fe4 = face[1][0];
  char C   = face[1][1];
  char Fe2 = face[1][2];
  char FC1 = face[0][0];
  char Fe1 = face[0][1];
  char FC2 = face[0][2];

  cubeFace* leftFace;
  cubeFace* rightFace;
  cubeFace* upFace;
  cubeFace* downFace;
  cubeFace* backFace;
};





class rubiksCube{
public:
  cubeFace frontFace;
  cubeFace leftFace;
  cubeFace rightFace;
  cubeFace upFace;
  cubeFace downFace;
  cubeFace backFace;
};


//Global Vairables
//Creates the 6 sides of the cube
cubeFace frontFace;
cubeFace leftFace;
cubeFace rightFace;
cubeFace upFace;
cubeFace downFace;
cubeFace backFace;




//Rotates the entire cube
rubiksCube rotateL(rubiksCube& cubeMain){
  //Creates Temperary Variables of the sides
  cubeFace tempRightCubeFace = cubeMain.rightFace;
  cubeFace tempFrontCubeFace = cubeMain.frontFace;
  cubeFace tempLeftFace = cubeMain.leftFace;
  cubeFace tempUpFace = cubeMain.upFace;
  cubeFace tempDownFace = cubeMain.downFace;
  cubeFace tempBackFace = cubeMain.backFace;
  
  cubeMain.frontFace = tempRightCubeFace;
  cubeMain.leftFace = tempFrontCubeFace;
  cubeMain.rightFace = tempBackFace;
  cubeMain.upFace = tempUpFace;
  cubeMain.downFace = tempDownFace;
  cubeMain.backFace = tempLeftFace;
  Serial.println("rotateL");

  return cubeMain;
}



//rotates the entire cube
rubiksCube rotateR(rubiksCube& cubeMain){
  //Creates Temperary Variables of the sides
  cubeFace tempRightCubeFace = cubeMain.rightFace;
  cubeFace tempFrontCubeFace = cubeMain.frontFace;
  cubeFace tempLeftFace = cubeMain.leftFace;
  cubeFace tempUpFace = cubeMain.upFace;
  cubeFace tempDownFace = cubeMain.downFace;
  cubeFace tempBackFace = cubeMain.backFace;
  
  cubeMain.frontFace = tempLeftFace;
  cubeMain.leftFace = tempBackFace;
  cubeMain.rightFace = tempFrontCubeFace;
  cubeMain.upFace = tempUpFace;
  cubeMain.downFace = tempDownFace;
  cubeMain.backFace = tempRightCubeFace;
    Serial.println("rotateR");

  return cubeMain;
}




rubiksCube moveR(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Front Faces
  char tempFrontFC2 = cubeMain.frontFace.FC2;
  char tempFrontFe2 = cubeMain.frontFace.Fe2;
  char tempFrontFC3 = cubeMain.frontFace.FC3;
  //Temp Up Faces
  char tempUpFC2 = cubeMain.upFace.FC2;
  char tempUpFe2 = cubeMain.upFace.Fe2;
  char tempUpFC3 = cubeMain.upFace.FC3;

  //Temp Back Faces
  char tempBackFC1 = cubeMain.backFace.FC1;
  char tempBackFe4 = cubeMain.backFace.Fe4;
  char tempbackFC4 = cubeMain.backFace.FC4;
  //Temp Right Face
  char tempRightFC1 = cubeMain.rightFace.FC1;
  char tempRightFe1 = cubeMain.rightFace.Fe1;
  char tempRightFC2 = cubeMain.rightFace.FC2;
  char tempRightFe4 = cubeMain.rightFace.Fe4;
  char tempRightFe2 = cubeMain.rightFace.Fe2;
  char tempRightFC4 = cubeMain.rightFace.FC4;
  char tempRightFe3 = cubeMain.rightFace.Fe3;
  char tempRightFC3 = cubeMain.rightFace.FC3;

  //Changes to the front face
  cubeMain.frontFace.FC2 = cubeMain.downFace.FC2;
  cubeMain.frontFace.Fe2 = cubeMain.downFace.Fe2;
  cubeMain.frontFace.FC3 = cubeMain.downFace.FC3;

  //Changes to the up face
  cubeMain.upFace.FC2 = tempFrontFC2;
  cubeMain.upFace.Fe2 = tempFrontFe2;
  cubeMain.upFace.FC3 = tempFrontFC3;

  //Chnages to the back face
  cubeMain.backFace.FC1 = tempUpFC3;
  cubeMain.backFace.Fe4 = tempUpFe2;
  cubeMain.backFace.FC4 = tempUpFC2;

  //Changes to the down face
  cubeMain.downFace.FC2 = tempBackFC1;
  cubeMain.downFace.Fe2 = tempBackFe4;
  cubeMain.downFace.FC3 = tempbackFC4;

  //Changes to the right face
  cubeMain.rightFace.FC1 = tempRightFC4;
  cubeMain.rightFace.Fe1 = tempRightFe4;
  cubeMain.rightFace.FC2 = tempRightFC1;
  cubeMain.rightFace.Fe4 = tempRightFe3;
  cubeMain.rightFace.Fe2 = tempRightFe1;
  cubeMain.rightFace.FC4 = tempRightFC3;
  cubeMain.rightFace.Fe3 = tempRightFe2;
  cubeMain.rightFace.FC3 = tempRightFC2;

  Serial.println("moveR");



  return cubeMain;
}




rubiksCube moveRPrime(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Down Faces
  char tempDownFC2 = cubeMain.downFace.FC2;
  char tempDownFe2 = cubeMain.downFace.Fe2;
  char tempDownFC3 = cubeMain.downFace.FC3;

  //Temp Front Faces
  char tempFrontFC2 = cubeMain.frontFace.FC2;
  char tempFrontFe2 = cubeMain.frontFace.Fe2;
  char tempFrontFC3 = cubeMain.frontFace.FC3;


  //Temp Back Faces
  char tempBackFC1 = cubeMain.backFace.FC1;
  char tempBackFe4 = cubeMain.backFace.Fe4;
  char tempBackFC4 = cubeMain.backFace.FC4;
  //Temp Right Face
  char tempRightFC1 = cubeMain.rightFace.FC1;
  char tempRightFe1 = cubeMain.rightFace.Fe1;
  char tempRightFC2 = cubeMain.rightFace.FC2;
  char tempRightFe4 = cubeMain.rightFace.Fe4;
  char tempRightFe2 = cubeMain.rightFace.Fe2;
  char tempRightFC4 = cubeMain.rightFace.FC4;
  char tempRightFe3 = cubeMain.rightFace.Fe3;
  char tempRightFC3 = cubeMain.rightFace.FC3;

  //Changes to the front face
  cubeMain.frontFace.FC2 = cubeMain.upFace.FC2;
  cubeMain.frontFace.Fe2 = cubeMain.upFace.Fe2;
  cubeMain.frontFace.FC3 = cubeMain.upFace.FC3;

  //Changes to the up face
  cubeMain.upFace.FC2 = tempBackFC4;
  cubeMain.upFace.Fe2 = tempBackFe4;
  cubeMain.upFace.FC3 = tempBackFC1;

  //Changes to the back face
  cubeMain.backFace.FC1 = tempDownFC3;
  cubeMain.backFace.Fe4 = tempDownFe2;
  cubeMain.backFace.FC4 = tempDownFC2;

  //Changes to the down face
  cubeMain.downFace.FC2 = tempFrontFC2;
  cubeMain.downFace.Fe2 = tempFrontFe2;
  cubeMain.downFace.FC3 = tempFrontFC3;

  //Changes to the right face
  cubeMain.rightFace.FC1 = tempRightFC2;
  cubeMain.rightFace.Fe1 = tempRightFe2;
  cubeMain.rightFace.FC2 = tempRightFC3;
  cubeMain.rightFace.Fe4 = tempRightFe1;
  cubeMain.rightFace.Fe2 = tempRightFe3;
  cubeMain.rightFace.FC4 = tempRightFC1;
  cubeMain.rightFace.Fe3 = tempRightFe4;
  cubeMain.rightFace.FC3 = tempRightFC4;

  Serial.println("moveRPrime");

  return cubeMain;
}




rubiksCube moveL(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Down Faces
  char tempDownFC1 = cubeMain.downFace.FC1;
  char tempDownFe4 = cubeMain.downFace.Fe4;
  char tempDownFC4 = cubeMain.downFace.FC4;

  //Temp Front Faces
  char tempFrontFC1 = cubeMain.frontFace.FC1;
  char tempFrontFe4 = cubeMain.frontFace.Fe4;
  char tempFrontFC4 = cubeMain.frontFace.FC4;


  //Temp Back Faces
  char tempBackFC2 = cubeMain.backFace.FC2;
  char tempBackFe2 = cubeMain.backFace.Fe2;
  char tempBackFC3 = cubeMain.backFace.FC3;
  //Temp left Face
  char templeftFC1 = cubeMain.leftFace.FC1;
  char templeftFe1 = cubeMain.leftFace.Fe1;
  char templeftFC2 = cubeMain.leftFace.FC2;
  char templeftFe4 = cubeMain.leftFace.Fe4;
  char templeftFe2 = cubeMain.leftFace.Fe2;
  char templeftFC4 = cubeMain.leftFace.FC4;
  char templeftFe3 = cubeMain.leftFace.Fe3;
  char templeftFC3 = cubeMain.leftFace.FC3;

  //Changes to the front face
  cubeMain.frontFace.FC1 = cubeMain.upFace.FC1;
  cubeMain.frontFace.Fe4 = cubeMain.upFace.Fe4;
  cubeMain.frontFace.FC4 = cubeMain.upFace.FC4;

  //Changes to the up face
  cubeMain.upFace.FC1 = tempBackFC2;
  cubeMain.upFace.Fe4 = tempBackFe2;
  cubeMain.upFace.FC4 = tempBackFC3;

  //Changes to the back face
  cubeMain.backFace.FC2 = tempDownFC4;
  cubeMain.backFace.Fe2 = tempDownFe4;
  cubeMain.backFace.FC3 = tempDownFC1;

  //Changes to the down face
  cubeMain.downFace.FC1 = tempFrontFC1;
  cubeMain.downFace.Fe4 = tempFrontFe4;
  cubeMain.downFace.FC4 = tempFrontFC4;

  //Changes to the left face
  cubeMain.leftFace.FC1 = templeftFC4;
  cubeMain.leftFace.Fe1 = templeftFe4;
  cubeMain.leftFace.FC2 = templeftFC1;
  cubeMain.leftFace.Fe4 = templeftFe3;
  cubeMain.leftFace.Fe2 = templeftFe1;
  cubeMain.leftFace.FC4 = templeftFC3;
  cubeMain.leftFace.Fe3 = templeftFe2;
  cubeMain.leftFace.FC3 = templeftFC2;

  Serial.println("moveL");
  

  return cubeMain;
}




rubiksCube moveLPrime(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Up Faces
  char tempUpFC1 = cubeMain.upFace.FC1;
  char tempUpFe4 = cubeMain.upFace.Fe4;
  char tempUpFC4 = cubeMain.upFace.FC4;

  //Temp Front Faces
  char tempFrontFC1 = cubeMain.frontFace.FC1;
  char tempFrontFe4 = cubeMain.frontFace.Fe4;
  char tempFrontFC4 = cubeMain.frontFace.FC4;


  //Temp Back Faces
  char tempBackFC2 = cubeMain.backFace.FC2;
  char tempBackFe2 = cubeMain.backFace.Fe2;
  char tempBackFC3 = cubeMain.backFace.FC3;
  //Temp left Face
  char templeftFC1 = cubeMain.leftFace.FC1;
  char templeftFe1 = cubeMain.leftFace.Fe1;
  char templeftFC2 = cubeMain.leftFace.FC2;
  char templeftFe4 = cubeMain.leftFace.Fe4;
  char templeftFe2 = cubeMain.leftFace.Fe2;
  char templeftFC4 = cubeMain.leftFace.FC4;
  char templeftFe3 = cubeMain.leftFace.Fe3;
  char templeftFC3 = cubeMain.leftFace.FC3;

  //Changes to the front face
  cubeMain.frontFace.FC1 = cubeMain.downFace.FC1;
  cubeMain.frontFace.Fe4 = cubeMain.downFace.Fe4;
  cubeMain.frontFace.FC4 = cubeMain.downFace.FC4;

  //Changes to the up face
  cubeMain.upFace.FC1 = tempFrontFC1;
  cubeMain.upFace.Fe4 = tempFrontFe4;
  cubeMain.upFace.FC4 = tempFrontFC4;

  //Changes to the back face
  cubeMain.backFace.FC2 = tempUpFC4;
  cubeMain.backFace.Fe2 = tempUpFe4;
  cubeMain.backFace.FC3 = tempUpFC1;

  //Changes to the down face
  cubeMain.downFace.FC1 = tempBackFC3;
  cubeMain.downFace.Fe4 = tempBackFe2;
  cubeMain.downFace.FC4 = tempBackFC2;

  //Changes to the left face
  cubeMain.leftFace.FC1 = templeftFC2;
  cubeMain.leftFace.Fe1 = templeftFe2;
  cubeMain.leftFace.FC2 = templeftFC3;
  cubeMain.leftFace.Fe4 = templeftFe1;
  cubeMain.leftFace.Fe2 = templeftFe3;
  cubeMain.leftFace.FC4 = templeftFC1;
  cubeMain.leftFace.Fe3 = templeftFe4;
  cubeMain.leftFace.FC3 = templeftFC4;
  Serial.println("moveLPrime");
  return cubeMain;
}




rubiksCube moveUpPrime(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Front Faces
  char tempFrontFC1 = cubeMain.frontFace.FC1;
  char tempFrontFe1 = cubeMain.frontFace.Fe1;
  char tempFrontFC2 = cubeMain.frontFace.FC2;
 

  //Temp Right Faces
  char tempRightFC1 = cubeMain.rightFace.FC1;
  char tempRightFe1 = cubeMain.rightFace.Fe1;
  char tempRightFC2 = cubeMain.rightFace.FC2;

  //Temp Back Faces
  char tempBackFC1 = cubeMain.backFace.FC1;
  char tempBackFe1 = cubeMain.backFace.Fe1;
  char tempBackFC2 = cubeMain.backFace.FC2;

  //Temp up Face
  char tempUpFC1 = cubeMain.upFace.FC1;
  char tempUpFe1 = cubeMain.upFace.Fe1;
  char tempUpFC2 = cubeMain.upFace.FC2;
  char tempUpFe4 = cubeMain.upFace.Fe4;
  char tempUpFe2 = cubeMain.upFace.Fe2;
  char tempUpFC4 = cubeMain.upFace.FC4;
  char tempUpFe3 = cubeMain.upFace.Fe3;
  char tempUpFC3 = cubeMain.upFace.FC3;

  //Changes to the front face
  cubeMain.frontFace.FC1 = cubeMain.leftFace.FC1;
  cubeMain.frontFace.Fe1 = cubeMain.leftFace.Fe1;
  cubeMain.frontFace.FC2 = cubeMain.leftFace.FC2;

  //Changes to the left face
  cubeMain.leftFace.FC1 = tempBackFC1;
  cubeMain.leftFace.Fe1 = tempBackFe1;
  cubeMain.leftFace.FC2 = tempBackFC2;

  //Changes to the back face
  cubeMain.backFace.FC1 = tempRightFC1;
  cubeMain.backFace.Fe1 = tempRightFe1;
  cubeMain.backFace.FC2 = tempRightFC2;

  //Changes to the right face
  cubeMain.rightFace.FC1 = tempFrontFC1;
  cubeMain.rightFace.Fe1 = tempFrontFe1;
  cubeMain.rightFace.FC2 = tempFrontFC2;

  //Changes to the up face
  cubeMain.upFace.FC1 = tempUpFC4;
  cubeMain.upFace.Fe1 = tempUpFe4;
  cubeMain.upFace.FC2 = tempUpFC1;
  cubeMain.upFace.Fe4 = tempUpFe3;
  cubeMain.upFace.Fe2 = tempUpFe1;
  cubeMain.upFace.FC4 = tempUpFC3;
  cubeMain.upFace.Fe3 = tempUpFe2;
  cubeMain.upFace.FC3 = tempUpFC2;

  Serial.println("moveUpPrime");
  return cubeMain;
}




rubiksCube moveUp(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Front Faces
  char tempFrontFC1 = cubeMain.frontFace.FC1;
  char tempFrontFe1 = cubeMain.frontFace.Fe1;
  char tempFrontFC2 = cubeMain.frontFace.FC2;
 
  //Temp Left Faces
  char tempLeftFC1 = cubeMain.leftFace.FC1;
  char tempLeftFe1 = cubeMain.leftFace.Fe1;
  char tempLeftFC2 = cubeMain.leftFace.FC2;


  //Temp Back Faces
  char tempBackFC1 = cubeMain.backFace.FC1;
  char tempBackFe1 = cubeMain.backFace.Fe1;
  char tempBackFC2 = cubeMain.backFace.FC2;

  //Temp up Face
  char tempUpFC1 = cubeMain.upFace.FC1;
  char tempUpFe1 = cubeMain.upFace.Fe1;
  char tempUpFC2 = cubeMain.upFace.FC2;
  char tempUpFe4 = cubeMain.upFace.Fe4;
  char tempUpFe2 = cubeMain.upFace.Fe2;
  char tempUpFC4 = cubeMain.upFace.FC4;
  char tempUpFe3 = cubeMain.upFace.Fe3;
  char tempUpFC3 = cubeMain.upFace.FC3;

  //Changes to the front face
  cubeMain.frontFace.FC1 = cubeMain.rightFace.FC1;
  cubeMain.frontFace.Fe1 = cubeMain.rightFace.Fe1;
  cubeMain.frontFace.FC2 = cubeMain.rightFace.FC2;

  //Changes to the left face
  cubeMain.leftFace.FC1 = tempFrontFC1;
  cubeMain.leftFace.Fe1 = tempFrontFe1;
  cubeMain.leftFace.FC2 = tempFrontFC2;

  //Changes to the back face
  cubeMain.backFace.FC1 = tempLeftFC1;
  cubeMain.backFace.Fe1 = tempLeftFe1;
  cubeMain.backFace.FC2 = tempLeftFC2;

  //Changes to the right face
  cubeMain.rightFace.FC1 = tempBackFC1;
  cubeMain.rightFace.Fe1 = tempBackFe1;
  cubeMain.rightFace.FC2 = tempBackFC2;

  //Changes to the up face
  cubeMain.upFace.FC1 = tempUpFC4;
  cubeMain.upFace.Fe1 = tempUpFe4;
  cubeMain.upFace.FC2 = tempUpFC1;
  cubeMain.upFace.Fe4 = tempUpFe3;
  cubeMain.upFace.Fe2 = tempUpFe1;
  cubeMain.upFace.FC4 = tempUpFC3;
  cubeMain.upFace.Fe3 = tempUpFe2;
  cubeMain.upFace.FC3 = tempUpFC2;

  Serial.println("moveUp");

  return cubeMain;
}




rubiksCube moveFront(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Right Faces
  char tempRightFC1 = cubeMain.rightFace.FC1;
  char tempRightFe4 = cubeMain.rightFace.Fe4;
  char tempRightFC4 = cubeMain.rightFace.FC4;
 
  //Temp Left Faces
  char tempLeftFC2 = cubeMain.leftFace.FC2;
  char tempLeftFe2 = cubeMain.leftFace.Fe2;
  char tempLeftFC3 = cubeMain.leftFace.FC3;


  //Temp Down Faces
  char tempDownFC1 = cubeMain.downFace.FC1;
  char tempDownFe1 = cubeMain.downFace.Fe1;
  char tempDownFC2 = cubeMain.downFace.FC2;

  //Temp UP Faces
  char tempUpFC4 = cubeMain.upFace.FC4;
  char tempUpFe3 = cubeMain.upFace.Fe3;
  char tempUpFC3 = cubeMain.upFace.FC3;

  //Temp front Face
  char tempFrontFC1 = cubeMain.frontFace.FC1;
  char tempFrontFe1 = cubeMain.frontFace.Fe1;
  char tempFrontFC2 = cubeMain.frontFace.FC2;
  char tempFrontFe4 = cubeMain.frontFace.Fe4;
  char tempFrontFe2 = cubeMain.frontFace.Fe2;
  char tempFrontFC4 = cubeMain.frontFace.FC4;
  char tempFrontFe3 = cubeMain.frontFace.Fe3;
  char tempFrontFC3 = cubeMain.frontFace.FC3;

  //Changes to the Up face
  cubeMain.upFace.FC4 = tempLeftFC3;
  cubeMain.upFace.Fe3 = tempLeftFe2;
  cubeMain.upFace.FC3 = tempLeftFC2;

  //Changes to the left face
  cubeMain.leftFace.FC3 = tempDownFC2;
  cubeMain.leftFace.Fe2 = tempDownFe1;
  cubeMain.leftFace.FC2 = tempDownFC1;

  //Changes to the down face
  cubeMain.downFace.FC1 = tempRightFC4;
  cubeMain.downFace.Fe1 = tempRightFe4;
  cubeMain.downFace.FC2 = tempRightFC1;

  //Changes to the right face
  cubeMain.rightFace.FC1 = tempUpFC4;
  cubeMain.rightFace.Fe4 = tempUpFe3;
  cubeMain.rightFace.FC4 = tempUpFC3; 

  //Changes to the front face
  cubeMain.frontFace.FC1 = tempFrontFC4;
  cubeMain.frontFace.Fe1 = tempFrontFe4;
  cubeMain.frontFace.FC2 = tempFrontFC1;
  cubeMain.frontFace.Fe4 = tempFrontFe3;
  cubeMain.frontFace.Fe2 = tempFrontFe1;
  cubeMain.frontFace.FC4 = tempFrontFC3;
  cubeMain.frontFace.Fe3 = tempFrontFe2;
  cubeMain.frontFace.FC3 = tempFrontFC2;

  Serial.println("moveFront");

  return cubeMain;
}




rubiksCube moveFrontPrime(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Right Faces
  char tempRightFC1 = cubeMain.rightFace.FC1;
  char tempRightFe4 = cubeMain.rightFace.Fe4;
  char tempRightFC4 = cubeMain.rightFace.FC4;
 
  //Temp Left Faces
  char tempLeftFC2 = cubeMain.leftFace.FC2;
  char tempLeftFe2 = cubeMain.leftFace.Fe2;
  char tempLeftFC3 = cubeMain.leftFace.FC3;


  //Temp Down Faces
  char tempDownFC1 = cubeMain.downFace.FC1;
  char tempDownFe1 = cubeMain.downFace.Fe1;
  char tempDownFC2 = cubeMain.downFace.FC2;

  //Temp UP Faces
  char tempUpFC4 = cubeMain.upFace.FC4;
  char tempUpFe3 = cubeMain.upFace.Fe3;
  char tempUpFC3 = cubeMain.upFace.FC3;

  //Temp front Face
  char tempFrontFC1 = cubeMain.frontFace.FC1;
  char tempFrontFe1 = cubeMain.frontFace.Fe1;
  char tempFrontFC2 = cubeMain.frontFace.FC2;
  char tempFrontFe4 = cubeMain.frontFace.Fe4;
  char tempFrontFe2 = cubeMain.frontFace.Fe2;
  char tempFrontFC4 = cubeMain.frontFace.FC4;
  char tempFrontFe3 = cubeMain.frontFace.Fe3;
  char tempFrontFC3 = cubeMain.frontFace.FC3;

  //Changes to the Up face
  cubeMain.upFace.FC4 = tempRightFC1;
  cubeMain.upFace.Fe3 = tempRightFe4;
  cubeMain.upFace.FC3 = tempRightFC4;

  //Changes to the left face
  cubeMain.leftFace.FC3 = tempUpFC4;
  cubeMain.leftFace.Fe2 = tempUpFe3;
  cubeMain.leftFace.FC2 = tempUpFC3;

  //Changes to the down face
  cubeMain.downFace.FC1 = tempLeftFC2;
  cubeMain.downFace.Fe1 = tempLeftFe2;
  cubeMain.downFace.FC2 = tempLeftFC3;

  //Changes to the right face
  cubeMain.rightFace.FC1 = tempDownFC2;
  cubeMain.rightFace.Fe4 = tempDownFe1;
  cubeMain.rightFace.FC4 = tempDownFC1; 

  //Changes to the front face
  cubeMain.frontFace.FC1 = tempFrontFC2;
  cubeMain.frontFace.Fe1 = tempFrontFe2;
  cubeMain.frontFace.FC2 = tempFrontFC3;
  cubeMain.frontFace.Fe4 = tempFrontFe1;
  cubeMain.frontFace.Fe2 = tempFrontFe3;
  cubeMain.frontFace.FC4 = tempFrontFC1;
  cubeMain.frontFace.Fe3 = tempFrontFe4;
  cubeMain.frontFace.FC3 = tempFrontFC4;
  Serial.println("moveFrontPrime");

  return cubeMain;
}




rubiksCube moveDown(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Right Faces
  char tempRightFC4 = cubeMain.rightFace.FC4;
  char tempRightFe3 = cubeMain.rightFace.Fe3;
  char tempRightFC3 = cubeMain.rightFace.FC3;
 
  //Temp Left Faces
  char tempLeftFC4 = cubeMain.leftFace.FC4;
  char tempLeftFe3 = cubeMain.leftFace.Fe3;
  char tempLeftFC3 = cubeMain.leftFace.FC3;


  //Temp Back Faces
  char tempBackFC4 = cubeMain.backFace.FC4;
  char tempBackFe3 = cubeMain.backFace.Fe3;
  char tempBackFC3 = cubeMain.backFace.FC3;

  //Temp Front Faces
  char tempFrontFC4 = cubeMain.frontFace.FC4;
  char tempFrontFe3 = cubeMain.frontFace.Fe3;
  char tempFrontFC3 = cubeMain.frontFace.FC3;

  //Temp down Face
  char tempDownFC1 = cubeMain.downFace.FC1;
  char tempDownFe1 = cubeMain.downFace.Fe1;
  char tempDownFC2 = cubeMain.downFace.FC2;
  char tempDownFe4 = cubeMain.downFace.Fe4;
  char tempDownFe2 = cubeMain.downFace.Fe2;
  char tempDownFC4 = cubeMain.downFace.FC4;
  char tempDownFe3 = cubeMain.downFace.Fe3;
  char tempDownFC3 = cubeMain.downFace.FC3;

  //Changes to the Back face
  cubeMain.backFace.FC4 = tempRightFC4;
  cubeMain.backFace.Fe3 = tempRightFe3;
  cubeMain.backFace.FC3 = tempRightFC3;

  //Changes to the left face
  cubeMain.leftFace.FC4 = tempBackFC4;
  cubeMain.leftFace.Fe3 = tempBackFe3;
  cubeMain.leftFace.FC3 = tempBackFC3;

  //Changes to the Front face
  cubeMain.frontFace.FC4 = tempLeftFC4;
  cubeMain.frontFace.Fe3 = tempLeftFe3;
  cubeMain.frontFace.FC3 = tempLeftFC3;

  //Changes to the right face
  cubeMain.rightFace.FC4 = tempFrontFC4;
  cubeMain.rightFace.Fe3 = tempFrontFe3;
  cubeMain.rightFace.FC3 = tempFrontFC3; 

  //Changes to the Down face
  cubeMain.downFace.FC1 = tempDownFC4;
  cubeMain.downFace.Fe1 = tempDownFe4;
  cubeMain.downFace.FC2 = tempDownFC1;
  cubeMain.downFace.Fe4 = tempDownFe3;
  cubeMain.downFace.Fe2 = tempDownFe1;
  cubeMain.downFace.FC4 = tempDownFC3;
  cubeMain.downFace.Fe3 = tempDownFe2;
  cubeMain.downFace.FC3 = tempDownFC2;

  Serial.println("moveDown");

  return cubeMain;
}




rubiksCube moveDownPrime(rubiksCube& cubeMain){
  //Temperary Vairables
  //Temp Right Faces
  char tempRightFC4 = cubeMain.rightFace.FC4;
  char tempRightFe3 = cubeMain.rightFace.Fe3;
  char tempRightFC3 = cubeMain.rightFace.FC3;
 
  //Temp Left Faces
  char tempLeftFC4 = cubeMain.leftFace.FC4;
  char tempLeftFe3 = cubeMain.leftFace.Fe3;
  char tempLeftFC3 = cubeMain.leftFace.FC3;


  //Temp Back Faces
  char tempBackFC4 = cubeMain.backFace.FC4;
  char tempBackFe3 = cubeMain.backFace.Fe3;
  char tempBackFC3 = cubeMain.backFace.FC3;

  //Temp Front Faces
  char tempFrontFC4 = cubeMain.frontFace.FC4;
  char tempFrontFe3 = cubeMain.frontFace.Fe3;
  char tempFrontFC3 = cubeMain.frontFace.FC3;

  //Temp down Face
  char tempDownFC1 = cubeMain.downFace.FC1;
  char tempDownFe1 = cubeMain.downFace.Fe1;
  char tempDownFC2 = cubeMain.downFace.FC2;
  char tempDownFe4 = cubeMain.downFace.Fe4;
  char tempDownFe2 = cubeMain.downFace.Fe2;
  char tempDownFC4 = cubeMain.downFace.FC4;
  char tempDownFe3 = cubeMain.downFace.Fe3;
  char tempDownFC3 = cubeMain.downFace.FC3;

  //Changes to the Back face
  cubeMain.backFace.FC4 = tempLeftFC4;
  cubeMain.backFace.Fe3 = tempLeftFe3;
  cubeMain.backFace.FC3 = tempLeftFC3;

  //Changes to the left face            
  cubeMain.leftFace.FC4 = tempFrontFC4;
  cubeMain.leftFace.Fe3 = tempFrontFe3;    
  cubeMain.leftFace.FC3 = tempFrontFC3;
  

  //Changes to the Front face
  cubeMain.frontFace.FC4 = tempRightFC4;
  cubeMain.frontFace.Fe3 = tempRightFe3;
  cubeMain.frontFace.FC3 = tempRightFC3;

  //Changes to the right face
  cubeMain.rightFace.FC4 = tempBackFC4;
  cubeMain.rightFace.Fe3 = tempBackFe3;
  cubeMain.rightFace.FC3 = tempBackFC3; 

  //Changes to the Down face
  cubeMain.downFace.FC1 = tempDownFC2;
  cubeMain.downFace.Fe1 = tempDownFe2;
  cubeMain.downFace.FC2 = tempDownFC3;
  cubeMain.downFace.Fe4 = tempDownFe1;
  cubeMain.downFace.Fe2 = tempDownFe3;
  cubeMain.downFace.FC4 = tempDownFC1;
  cubeMain.downFace.Fe3 = tempDownFe4;
  cubeMain.downFace.FC3 = tempDownFC4;

  Serial.println("moveDownPrime");

  return cubeMain;
}




void printFace(cubeFace cubeMainFace){
  char face[3][3];
  face[2][0] = cubeMainFace.FC4;
  face[2][1] = cubeMainFace.Fe3;
  face[2][2] = cubeMainFace.FC3;
  face[1][0] = cubeMainFace.Fe4;
  face[1][1] = cubeMainFace.C;
  face[1][2] = cubeMainFace.Fe2;
  face[0][0] = cubeMainFace.FC1;
  face[0][1] = cubeMainFace.Fe1;
  face[0][2] = cubeMainFace.FC2;

    for(int i=0 ; i<=2 ; i++)
    {
        for(int j=0 ; j<=2 ; j++)
            Serial.print( *(*(face+i)+j));
        Serial.println("");
    }
    Serial.println("");
}


boolean whiteCrossCheck (rubiksCube cubeMain){
  if(cubeMain.upFace.Fe1 == 'W' && cubeMain.upFace.Fe2 == 'W' && cubeMain.upFace.Fe3 == 'W' && cubeMain.upFace.Fe4 == 'W'){ //If you have a white cross
      if(cubeMain.frontFace.C == cubeMain.frontFace.Fe1 && cubeMain.rightFace.C == cubeMain.rightFace.Fe1 && cubeMain.leftFace.C == cubeMain.leftFace.Fe1 && cubeMain.backFace.C == cubeMain.backFace.Fe1){ //If the cross is oriented properly
        Serial.println("Yes White Cross");
        return true;
      } else{
        Serial.println("You have a white cross but not oriented properly");
        return false;
      }
  } else{
    Serial.println("No White Cross");
    return false;
  }
}


String whiteEdgeFinder(rubiksCube cubeMain){
    if(cubeMain.frontFace.Fe1 == 'W' || cubeMain.upFace.Fe3 == 'W'){
      Serial.println("White Edge Found On Top");
      return "TOP EDGE";
    } else if(cubeMain.frontFace.Fe2 == 'W' || cubeMain.rightFace.Fe4 == 'W'){
      Serial.println("White Edge Found On Right");
      return "RIGHT EDGE";
    } else if (cubeMain.frontFace.Fe3 == 'W' || cubeMain.downFace.Fe1 == 'W'){
      Serial.println("White Edge Found On Bottom");
      return "BOTTOM EDGE";
    } else if (cubeMain.frontFace.Fe4 == 'W' || cubeMain.leftFace.Fe2 == 'W'){
      Serial.println("White Edge Found On Left");
      return "LEFT EDGE";
    } else {
      Serial.println("No White Edge Found");
      return "NO EDGE";
    }
}


//White Cross Function
rubiksCube whiteCrossMaker (rubiksCube& cubeMain){
    //Until the white cross is  solved
     //while (whiteCrossCheck(cubeMain) == false){
      //If there is a white edge piece on the top
      if(whiteEdgeFinder(cubeMain) == "TOP EDGE"){
        //If the white side is facing up
        if(cubeMain.upFace.Fe3 == 'W'){
          //If the piece is on the correct side already
          if(cubeMain.frontFace.C == cubeMain.frontFace.Fe1){
            Serial.println("White Top Edge Piece Already In Place");
          } else{
            //If the Piece isn't on the correct side
            Serial.println("Moving White Piece On Facing Up Into Place");
            //Take it to the Bottom
            moveFront(cubeMain);
            moveFront(cubeMain);

            //Move the piece to the correct side
            Serial.println("Entering Loop ");
            while(cubeMain.frontFace.Fe3 != cubeMain.frontFace.C){
              moveDown(cubeMain);
              rotateL(cubeMain);
            }
            Serial.println("Finished Loop, Now on the Correct Side");
            //Move the piece to the top
            moveFront(cubeMain);
            moveFront(cubeMain);
            Serial.println("White edge piece now in place");
          }
        }
      }
   // }
    
  return cubeMain; 
}







//Main Code Loop
void loop(){
  //Creates the Main Rubiks cube
  rubiksCube mainCube;

  //Defines the Faces of the cube
  mainCube.backFace = backFace;
  mainCube.frontFace = frontFace;
  mainCube.leftFace = leftFace;
  mainCube.rightFace = rightFace;
  mainCube.upFace = upFace;
  mainCube.frontFace = frontFace;

  mainCube.frontFace.FC1 = 'Y';
  mainCube.frontFace.FC2 = 'B';
  mainCube.frontFace.FC3 = 'R';
  mainCube.frontFace.FC4 = 'Y';
  mainCube.frontFace.Fe1 = 'B';
  mainCube.frontFace.Fe2 = 'O';
  mainCube.frontFace.Fe3 = 'Y';
  mainCube.frontFace.Fe4 = 'R';
  mainCube.frontFace.C = 'G';

  mainCube.rightFace.FC1 = 'R';
  mainCube.rightFace.FC2 = 'O';
  mainCube.rightFace.FC3 = 'G';
  mainCube.rightFace.FC4 = 'O';
  mainCube.rightFace.Fe1 = 'O';
  mainCube.rightFace.Fe2 = 'R';
  mainCube.rightFace.Fe3 = 'R';
  mainCube.rightFace.Fe4 = 'O';
  mainCube.rightFace.C = 'R';

  
  mainCube.leftFace.FC1 = 'Y';
  mainCube.leftFace.FC2 = 'B';
  mainCube.leftFace.FC3 = 'R';
  mainCube.leftFace.FC4 = 'O';
  mainCube.leftFace.Fe1 = 'R';
  mainCube.leftFace.Fe2 = 'G';
  mainCube.leftFace.Fe3 = 'O';
  mainCube.leftFace.Fe4 = 'O';
  mainCube.leftFace.C = 'O';

  mainCube.backFace.FC1 = 'G';
  mainCube.backFace.FC2 = 'B';
  mainCube.backFace.FC3 = 'Y';
  mainCube.backFace.FC4 = 'R';
  mainCube.backFace.Fe1 = 'B';
  mainCube.backFace.Fe2 = 'W';
  mainCube.backFace.Fe3 = 'B';
  mainCube.backFace.Fe4 = 'W';
  mainCube.backFace.C = 'B';

  mainCube.upFace.FC1 = 'O';
  mainCube.upFace.FC2 = 'R';
  mainCube.upFace.FC3 = 'B';
  mainCube.upFace.FC4 = 'W';
  mainCube.upFace.Fe1 = 'W';
  mainCube.upFace.Fe2 = 'Y';
  mainCube.upFace.Fe3 = 'W';
  mainCube.upFace.Fe4 = 'Y';
  mainCube.upFace.C = 'W';

  mainCube.downFace.FC1 = 'Y';
  mainCube.downFace.FC2 = 'W';
  mainCube.downFace.FC3 = 'Y';
  mainCube.downFace.FC4 = 'G';
  mainCube.downFace.Fe1 = 'R';
  mainCube.downFace.Fe2 = 'B';
  mainCube.downFace.Fe3 = 'Y';
  mainCube.downFace.Fe4 = 'B';
  mainCube.downFace.C = 'Y';

  whiteCrossMaker(mainCube);
  delay(1000);

}