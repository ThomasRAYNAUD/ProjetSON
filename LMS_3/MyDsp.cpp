#include "MyDsp.h"

#define MULT_16 32767
#define DIV_16 0.0000305185
#define BUFFER_SIZE NUM_COEFFICIENTS

MyDsp::MyDsp() : AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
                noise(),
                oneZero(),
                mu(0.0001),
                adaptSignal(0.0),
                error(0),
                output_H(0)
{
    for (int i = 0; i < NUM_COEFFICIENTS; i++) {
        coefficients[i] = 0.0 ;
        input[i] = 0.0 ;
    }
}

MyDsp::~MyDsp() {}


void MyDsp::update(void) {
  audio_block_t *outBlock[AUDIO_OUTPUTS];
  audio_block_t *inBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    inBlock[channel] = receiveReadOnly(channel);
    outBlock[channel] = allocate();
      if (outBlock[channel]) {
            for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
                float currentSample = noise.tick() * 0.5 ;
                for (int i = NUM_COEFFICIENTS - 1; i > 0; i--) {
                        input[i] = input[i - 1];
                }
                input[0] = currentSample;
                float headset = input[0] ;
                
                if(inBlock[channel]){
                   output_H = inBlock[channel]->data[i]*DIV_16;
                }
                  adaptSignal = 0 ;
                for (int v = 0; v < NUM_COEFFICIENTS; v++) {
                    adaptSignal += input[v] * coefficients[v];
                }
                error = output_H - adaptSignal ;
                Serial.println(error*10);
                float norm = 0;
                for (int j = 0 ; j < NUM_COEFFICIENTS ; j++){
                  norm += input[j]*input[j];
                }
                for (int k = 0; k < NUM_COEFFICIENTS; k++) {
                    coefficients[k] += (mu * error * input[k])/norm ;
                }
                int16_t val = headset * MULT_16;
                outBlock[channel]->data[i] = val; 
              }
              
            transmit(outBlock[channel], channel);
            if(inBlock[channel]) release(inBlock[channel]);
            release(outBlock[channel]);
        }
    }
}
