/*
  Configuration.h should be the central repository for system constants, pin definitions, and compile-time flags.
  This file controls the build target (Simulator vs Hardware).
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// SYSTEM MODE CONFIGURATION
// instruction!!!! Uncomment the line below to run in SIMULATOR mode.
// instruction!!!!!! Comment it out to compile for the ESP32 HARDWARE.
#define SIMULATOR_MODE 

// ESP32 HARDWARE PIN DEFINITIONS
// Using generic GPIOs suitable for the ESP32. 
// OBS! Avoid using pins 0, 2, 12, 15, as they are strapping pins that determine boot modes.

// motor output pins (PWM to ESC)
#define PIN_MOTOR_LEFT_PWM 25
#define PIN_MOTOR_RIGHT_PWM 26

// encoder input pins (Interrupt capable) 
// these are placeholders for future expansion ask Aiden about it if unsure
#define PIN_ENC_LEFT_A 32
#define PIN_ENC_LEFT_B 33
#define PIN_ENC_RIGHT_A 27
#define PIN_ENC_RIGHT_B 14

// sensor input pins (Analog/Digital)
#define PIN_SENSOR_FRONT 34 
// input-only pin (good for ADC)
#define PIN_SENSOR_LEFT 35 
// input-only pin
#define PIN_SENSOR_RIGHT 39 
// input-only pin (VN)


// MOTOR & PWM PHYSICS CONSTANTS
// standard ESCs expect a 50hz update rate.
#define PWM_FREQUENCY 50      
// We use 16-bit resolution for precise throttle control.
#define PWM_RESOLUTION 16      

// ESC pulse width definitions (in ms)
// verify these with your specific ESC datasheet when motor model is known (ZZ)
#define ESC_MIN_US 1000    
// full reverse or stop
#define ESC_MAX_US 2000    
// full forward
#define ESC_NEUTRAL_US 1500   
// center / stop

// MAZE & ROBOT GEOMETRY
#define CELL_SIZE_MM 160.0  
// micromouse cell size but since walls are supposed to be 10mm each, decision was 160 instead of 180 (standard micromouse size), ask Aiden for further questions
#define ROBOT_WHEEL_DIA ZZ
// wheel diameter in mm PLACEHOLDER (ZZ)
#define ROBOT_TRACK_WIDTH ZZ
// distans between wheels in mm PLACEHOLDER (ZZ)

#endif // CONFIGURATION_H
