/* 
   Sample sketch for Multimedia Keys
   Alternately mute and un-mute the system volume every five seconds.
 
   http://stefanjones.ca/blog/arduino-leonardo-remote-multimedia-keys/
*/
const byte sensorDataBits = 10;
const int blockSize = 4;

void setup() { 
  Serial.begin(115200);
}

void getByteBlock(int decimalBlock[], byte byteBlock[]){
    int b = 0;
    byte byteBitPos=0;
    for (int d=0; d<blockSize; d++){
        for (byte bitPos=0; bitPos<sensorDataBits; bitPos++) {
            int byteIndex = b/8;
            // Serial.print(" byte");
            // Serial.print(byteIndex);
            // Serial.print("[");
            // Serial.print(byteBitPos);
            // Serial.print("] = ");
            // Serial.print(bitRead(decimalBlock[d], bitPos));
            // Serial.println();
            bitWrite(byteBlock[byteIndex], byteBitPos, bitRead(decimalBlock[d], bitPos));            
            b++;
            if (byteBitPos==7){
                byteBitPos=0;
            }else{
                byteBitPos++;
            }
        }
    }
}
 
void loop() {
    while(!Serial); // Do nothing until serial input is received
    // set the vars
    int HIP_CENTER_PITCH = 789;
    int HIP_CENTER_YAW = 789;
    int HIP_CENTER_ROLL = 789;
    int SPINE_PITCH = 789;
    int SPINE_YAW = 789;
    int SPINE_ROLL = 789;
    
    int HAND_LEFT_THUMB_PITCH = 789;
    int HAND_LEFT_THUMB_YAW = 789;
    int HAND_LEFT_2_PITCH = 789;
    int HAND_LEFT_3_PITCH = 789;
    int HAND_LEFT_4_PITCH = 789;
    int HAND_LEFT_5_PITCH = 789;
    int WRIST_LEFT_PITCH = 789;
    int WRIST_LEFT_YAW = 789;
    int ELBOW_LEFT_PITCH = 789;
    int ELBOW_LEFT_ROLL = 789;
    int SHOULDER_LEFT_PITCH = 789;
    int SHOULDER_LEFT_YAW = 789;
    int SHOULDER_LEFT_ROLL = 789;
    int HIP_LEFT_PITCH = 789;
    int HIP_LEFT_YAW = 789;
    int HIP_LEFT_ROLL = 789;
    int KNEE_LEFT_PITCH = 789;
    int ANKLE_LEFT_PITCH = 789;
    int LEFT_BUTTONS = 0;

    int HAND_RIGHT_THUMB_PITCH = 789;
    int HAND_RIGHT_THUMB_YAW = 789;
    int HAND_RIGHT_2_PITCH = 789;
    int HAND_RIGHT_3_PITCH = 789;
    int HAND_RIGHT_4_PITCH = 789;
    int HAND_RIGHT_5_PITCH = 789;
    int WRIST_RIGHT_PITCH = 789;
    int WRIST_RIGHT_YAW = 789;
    int ELBOW_RIGHT_PITCH = 789;
    int ELBOW_RIGHT_ROLL = 789;
    int SHOULDER_RIGHT_PITCH = 789;
    int SHOULDER_RIGHT_YAW = 789;
    int SHOULDER_RIGHT_ROLL = 789;
    int HIP_RIGHT_PITCH = 789;
    int HIP_RIGHT_YAW = 789;
    int HIP_RIGHT_ROLL = 789;
    int KNEE_RIGHT_PITCH = 789;
    int ANKLE_RIGHT_PITCH = 789; 
    int RIGHT_BUTTONS = 0;

    // ---- 10 bit -----
    // 1100010101  = 789
    // 1100010101  = 789
    // 1100010101  = 789

    // ---- 8 bit -----
    // 00010101     = 21
    // 01010111     = 87
    // 00001100     = 12

    // create byte blocks
    int CENTER_A[blockSize] = { 
                        HIP_CENTER_PITCH,
                        HIP_CENTER_YAW,
                        HIP_CENTER_ROLL,
                        0 };
    byte bCENTER_A[blockSize+1]={};
    getByteBlock(CENTER_A, bCENTER_A);

    int CENTER_B[blockSize] = { 
                        SPINE_PITCH,
                        SPINE_YAW,
                        SPINE_ROLL,
                        0 };
    byte bCENTER_B[blockSize+1]={};
    getByteBlock(CENTER_B, bCENTER_B);

    int LEFT_A[blockSize] = { 
                        HAND_LEFT_THUMB_PITCH,
                        HAND_LEFT_THUMB_YAW,
                        HAND_LEFT_2_PITCH,
                        HAND_LEFT_3_PITCH };
    byte bLEFT_A[blockSize+1]={};
    getByteBlock(LEFT_A, bLEFT_A);

    int LEFT_B[blockSize] = { 
                        HAND_LEFT_4_PITCH,
                        HAND_LEFT_5_PITCH,
                        WRIST_LEFT_PITCH,
                        WRIST_LEFT_YAW };
    byte bLEFT_B[blockSize+1]={};
    getByteBlock(LEFT_B, bLEFT_B);

    int LEFT_C[blockSize] = { 
                        ELBOW_LEFT_PITCH,
                        ELBOW_LEFT_ROLL,
                        SHOULDER_LEFT_PITCH,
                        SHOULDER_LEFT_YAW };
    byte bLEFT_C[blockSize+1]={};
    getByteBlock(LEFT_C, bLEFT_C);

    int LEFT_D[blockSize] = { 
                        SHOULDER_LEFT_ROLL,
                        HIP_LEFT_PITCH,
                        HIP_LEFT_YAW,
                        HIP_LEFT_ROLL };
    byte bLEFT_D[blockSize+1]={};
    getByteBlock(LEFT_D, bLEFT_D);

    int LEFT_E[blockSize] = { 
                        KNEE_LEFT_PITCH,
                        ANKLE_LEFT_PITCH,
                        LEFT_BUTTONS,
                        0 };
    byte bLEFT_E[blockSize+1]={};
    getByteBlock(LEFT_E, bLEFT_E);

    int RIGHT_A[blockSize] = { 
                        HAND_RIGHT_THUMB_PITCH,
                        HAND_RIGHT_THUMB_YAW,
                        HAND_RIGHT_2_PITCH,
                        HAND_RIGHT_3_PITCH };
    byte bRIGHT_A[blockSize+1]={};
    getByteBlock(RIGHT_A, bRIGHT_A);

    int RIGHT_B[blockSize] = { 
                        HAND_RIGHT_4_PITCH,
                        HAND_RIGHT_5_PITCH,
                        WRIST_RIGHT_PITCH,
                        WRIST_RIGHT_YAW };
    byte bRIGHT_B[blockSize+1]={};
    getByteBlock(RIGHT_B, bRIGHT_B);

    int RIGHT_C[blockSize] = { 
                        ELBOW_RIGHT_PITCH,
                        ELBOW_RIGHT_ROLL,
                        SHOULDER_RIGHT_PITCH,
                        SHOULDER_RIGHT_YAW };
    byte bRIGHT_C[blockSize+1]={};
    getByteBlock(RIGHT_C, bRIGHT_C);

    int RIGHT_D[blockSize] = { 
                        SHOULDER_RIGHT_ROLL,
                        HIP_RIGHT_PITCH,
                        HIP_RIGHT_YAW,
                        HIP_RIGHT_ROLL };
    byte bRIGHT_D[blockSize+1]={};
    getByteBlock(RIGHT_D, bRIGHT_D);

    int RIGHT_E[blockSize] = { 
                        KNEE_RIGHT_PITCH,
                        ANKLE_RIGHT_PITCH,
                        RIGHT_BUTTONS,
                        0 };
    byte bRIGHT_E[blockSize+1]={};
    getByteBlock(RIGHT_E, bRIGHT_E);
    
    byte report[64]={
        bCENTER_A[0],       // byte 1
        bCENTER_A[1],       // byte 2 
        bCENTER_A[2],       // byte 3
        bCENTER_A[3],       // byte 4
        bCENTER_A[4],       // byte 5
        bCENTER_B[0],       // byte 6
        bCENTER_B[1],       // byte 7
        bCENTER_B[2],       // byte 8
        bCENTER_B[3],       // byte 9
        bCENTER_B[4],       // byte 10
        bLEFT_A[0],         // byte 11
        bLEFT_A[1],         // byte 12
        bLEFT_A[2],         // byte 13
        bLEFT_A[3],         // byte 14
        bLEFT_A[4],         // byte 15
        bLEFT_B[0],         // byte 16
        bLEFT_B[1],         // byte 17
        bLEFT_B[2],         // byte 18
        bLEFT_B[3],         // byte 19
        bLEFT_B[4],         // byte 20
        bLEFT_C[0],         // byte 21
        bLEFT_C[1],         // byte 22
        bLEFT_C[2],         // byte 23
        bLEFT_C[3],         // byte 24
        bLEFT_C[4],         // byte 25
        bLEFT_D[0],         // byte 26
        bLEFT_D[1],         // byte 27
        bLEFT_D[2],         // byte 28
        bLEFT_D[3],         // byte 29
        bLEFT_D[4],         // byte 30
        bLEFT_E[0],         // byte 31
        bLEFT_E[1],         // byte 32
        bLEFT_E[2],         // byte 33
        bLEFT_E[3],         // byte 34
        bLEFT_E[4],         // byte 35
        bRIGHT_A[0],        // byte 36
        bRIGHT_A[1],        // byte 37
        bRIGHT_A[2],        // byte 38
        bRIGHT_A[3],        // byte 39
        bRIGHT_A[4],        // byte 40
        bRIGHT_B[0],        // byte 41
        bRIGHT_B[1],        // byte 42
        bRIGHT_B[2],        // byte 43
        bRIGHT_B[3],        // byte 44
        bRIGHT_B[4],        // byte 45
        bRIGHT_C[0],        // byte 46
        bRIGHT_C[1],        // byte 47
        bRIGHT_C[2],        // byte 48
        bRIGHT_C[3],        // byte 49
        bRIGHT_C[4],        // byte 50
        bRIGHT_D[0],        // byte 51
        bRIGHT_D[1],        // byte 52
        bRIGHT_D[2],        // byte 53
        bRIGHT_D[3],        // byte 54
        bRIGHT_D[4],        // byte 55
        bRIGHT_E[0],        // byte 56
        bRIGHT_E[1],        // byte 57
        bRIGHT_E[2],        // byte 58
        bRIGHT_E[3],        // byte 59
        bRIGHT_E[4],        // byte 60
        B00000000,          // byte 61
        B00000000,          // byte 62
        B00000000,          // byte 63
        B00000000};         // byte 64

    Suit.sendReport(report);
    delay(2000);
}
