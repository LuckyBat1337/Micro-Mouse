# Micro-Mouse
Micro mouse project for school



General information ot read before you program!!!! OBS!!! OBBBSSS!!!!!!!!!!
The code that has been written is right now almost ready to use the mackorone API and driving hardware, Motors.h and Motors.cpp are not written so it will very obviously not work yet.
The code in Micromouse.ino is very simple maze solving code that should work once Motors.cpp and Motors.h are done. Open-loop control (assuming x% power for x seconds moves the robot 100mm)
seems like the easiest way to implement movement, but since time doesn't seem like an issue and since open-loop is annoying and needs tweaking to work properly closed-loop control seems better.
For closed-loop control we would need encoders. A file named "Encoders.cpp" and "Encoders.h" could be created and there is already "attachInterrupt()" that would be used to increment counters,
not sure how the encoder works, how it changes. Someone should try and find out. Someone should also read more about PID controllers to find out how to implement this.


CLOSED LOOP CONTROL!!!:
For closed loop a formula that looks like "target_ticks = mm * TICKS_PER_MM; while(current_ticks < target_ticks) {... }" 
PID controller research:


ZZ = things that are needed for review, ZZ chosen as there is not a need for any function to be called ZZ and ZZ is easily able to be looked up in a document by "Ctrl + F".

Standard for how the code should look is as follows:

For good practice no namespace will be used unless it is a local namespace created internally for the project.

If a variable is a constant variable it should be written in the form of all capitalized letters, in the case of there being more than one word in the variable name it should use an underscore (_), (e.g. WHEEL_DIAMETER)

For variables with one word keep it uncapitalized for the entirety (e.g. move() ).

For variables with two or more words keep it uncapitalized on the first word, then without spaces capitalize the second so on (e.g. moveRight() or turnLeftOnWallRight() ).

indentation style follows standard procedure for c++ being function name, bracket, new line, code, new line, bracket. 
(e.g. 
main(){
   code:
} 
).
