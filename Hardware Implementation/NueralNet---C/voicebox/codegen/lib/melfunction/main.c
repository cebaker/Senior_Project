/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 18-Apr-2018 00:48:20
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "allheaders.h"
#include "wave.h"

/* Function Declarations */
double * getData();
static void argInit_1x16000_real_T(double result[16000]);
static double argInit_real_T(void);
static void main_melfunction(void);
/* Global Variable Definitions*/

unsigned char buffer4[4];
unsigned char buffer2[2];

double features[24];

 FILE *ptr;
 char *filename;
 char *dataFilename;
 struct HEADER header;
/* Function Definitions */

/*
 * Arguments    : double result[16000]
 * Return Type  : void
 */
static void argInit_1x16000_real_T(double result[16000])
{
  static double * dataAry;
  dataAry = getData();
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 16000; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = dataAry[idx1];
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_melfunction(void)
{
  
  static double dv6[16000];
  double c[24];
  
  /* Initialize function 'melfunction' input arguments. */
  /* Initialize function input argument 'x'. */
  /* Call the entry-point 'melfunction'. */
  argInit_1x16000_real_T(dv6);
  melfunction(dv6, c);
  printf("\n===============Features=============\n");
  for(int i = 0 ; i < sizeof(c)/sizeof(double); i++){
    printf("%f\n",c[i]);
  }
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  melfunction_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_melfunction();

  /* Terminate the application.
     You do not need to do this more than one time. */
  melfunction_terminate();
  return 0;
}
double * getData(){
 double * dataAry = malloc(16000 *sizeof(double));
 filename = (char*) malloc(sizeof(char) * 1024);
 

 if (filename == NULL) {
   printf("Error in malloc\n");
   exit(1);
 }

 
 filename = "TEST.WAV";

 // open file
 printf("Opening  files..\n");
 ptr = fopen(filename, "rb");
 if (ptr == NULL) {
  printf("Error opening file\n");
  exit(1);
 }
 
 int read = 0;
 
 // read header parts

 read = fread(header.riff, sizeof(header.riff), 1, ptr);

 read = fread(buffer4, sizeof(buffer4), 1, ptr);
 
 // convert little endian to big endian 4 byte int
 header.overall_size  = buffer4[0] | 
            (buffer4[1]<<8) | 
            (buffer4[2]<<16) | 
            (buffer4[3]<<24);

 read = fread(header.wave, sizeof(header.wave), 1, ptr);
 read = fread(header.fmt_chunk_marker, sizeof(header.fmt_chunk_marker), 1, ptr);
 read = fread(buffer4, sizeof(buffer4), 1, ptr);

 // convert little endian to big endian 4 byte integer
 header.length_of_fmt = buffer4[0] |
              (buffer4[1] << 8) |
              (buffer4[2] << 16) |
              (buffer4[3] << 24);

 read = fread(buffer2, sizeof(buffer2), 1, ptr); 
 
 header.format_type = buffer2[0] | (buffer2[1] << 8);
 char format_name[10] = "";
 if (header.format_type == 1)
   strcpy(format_name,"PCM"); 
 else if (header.format_type == 6)
  strcpy(format_name, "A-law");
 else if (header.format_type == 7)
  strcpy(format_name, "Mu-law");

 read = fread(buffer2, sizeof(buffer2), 1, ptr);

 header.channels = buffer2[0] | (buffer2[1] << 8);

 read = fread(buffer4, sizeof(buffer4), 1, ptr);

 header.sample_rate = buffer4[0] |
            (buffer4[1] << 8) |
            (buffer4[2] << 16) |
            (buffer4[3] << 24);

 read = fread(buffer4, sizeof(buffer4), 1, ptr);
 //byte rate bit rate , header.byterate, header.byterate*8
 header.byterate  = buffer4[0] |
            (buffer4[1] << 8) |
            (buffer4[2] << 16) |
            (buffer4[3] << 24);

 read = fread(buffer2, sizeof(buffer2), 1, ptr);
 //block alignment
 header.block_align = buffer2[0] |
          (buffer2[1] << 8);
 //read buffer
 read = fread(buffer2, sizeof(buffer2), 1, ptr);
 //bits per sample
 header.bits_per_sample = buffer2[0] |
          (buffer2[1] << 8);
 //data Marker header.data_chunk_header
 read = fread(header.data_chunk_header, sizeof(header.data_chunk_header), 1, ptr);

 read = fread(buffer4, sizeof(buffer4), 1, ptr);
 //size of data chunks header.data_size
 header.data_size = buffer4[0] |
        (buffer4[1] << 8) |
        (buffer4[2] << 16) | 
        (buffer4[3] << 24 );
 // calculate no.of samples
 long num_samples = (8 * header.data_size) / (header.channels * header.bits_per_sample);

 
 //size of samples
 long size_of_each_sample = (header.channels * header.bits_per_sample) / 8;
 // calculate duration of file
 float duration_in_seconds = (float) header.overall_size / header.byterate;

 // read each sample from data chunk if PCM
 if (header.format_type == 1) { // PCM
    printf("Dump sample data? Y/N?");
  char c = 'n';
  scanf("%c", &c);
  if (c == 'Y' || c == 'y') { 
    long i =0;
    char data_buffer[size_of_each_sample];
    int  size_is_correct = 1;

    // make sure that the bytes-per-sample is completely divisible by num.of channels
    long bytes_in_each_channel = (size_of_each_sample / header.channels);
    if ((bytes_in_each_channel  * header.channels) != size_of_each_sample) {
      size_is_correct = 0;
    }
 
    if (size_is_correct) { 
          // the valid amplitude range for values based on the bits per sample
      long low_limit = 0l;
      long high_limit = 0l;

      switch (header.bits_per_sample) {
        case 8:
          low_limit = -128;
          high_limit = 127;
          break;
        case 16:
          low_limit = -32768;
          high_limit = 32767;
          break;
        case 32:
          low_limit = -2147483648;
          high_limit = 2147483647;
          break;
      }
      //dumb counting
              
             //allocate array to save data
           int j = 0;
      //printf("\n\n.Valid range for data values : %ld to %ld \n", low_limit, high_limit);
      for (i =1; i <= num_samples; i++) {
        //printf("==========Sample %ld / %ld=============\n", i, num_samples);
        read = fread(data_buffer, sizeof(data_buffer), 1, ptr);
        if (read == 1) {
        
          // dump the data read
          unsigned int  xchannels = 0;
          double data_in_channel = 0;

          for (xchannels = 0; xchannels < header.channels; xchannels ++ ) {
            //printf("Channel#%d : ", (xchannels+1));
            // convert data from little endian to big endian based on bytes in each channel sample
            if (bytes_in_each_channel == 4) {
              data_in_channel = data_buffer[0] | 
                        (data_buffer[1]<<8) | 
                        (data_buffer[2]<<16) | 
                        (data_buffer[3]<<24);
            }
            else if (bytes_in_each_channel == 2) {
              data_in_channel = data_buffer[0] |
                        (data_buffer[1] << 8);
            }
            else if (bytes_in_each_channel == 1) {
              data_in_channel = data_buffer[0];
            }

            //printf("%.4f", data_in_channel);
            
            dataAry[j] = data_in_channel / 32767.7;
            //printf("%e ", data_in_channel/32767.7);
            j++;

            // check if value was in range
            if (data_in_channel < low_limit || data_in_channel > high_limit)
              printf("**value out of range\n");

            //printf(" | ");
          }

          //printf("\n");
        }
        else {
          printf("Error reading file. %d bytes\n", read);
          break;
        }

      } 

    } 

   } 
 }

 //for(int i = 0 ; i < 24)
 printf("Writing data to file..\n"); 
 printf("Closing file..\n");
 fclose(ptr);

 

  // cleanup before quitting
 free(filename);
 return dataAry;
 
}

