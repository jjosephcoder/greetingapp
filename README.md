This is a greeting application which I was inspired to create for my daugther 21st Birthday after
seeing somethng similar on Facebook.

I decided to add a windows wav file for the keyboard stroke noises and to do so I imported the winmm library.

The project taught me how to create a cursor flashing effect using the block ascii chracter value 254 and assigning it
to a char variable I used within a for loop with encapsulated with a couple of sleep command, aswell as the \b switch
to cout for deleting the block after outputting it to the screen.

I also learnt how to turn off the flashing cursor in the terminal and created a cursoroff() function for future use.

I plan to expand this porject in the future to use Google Translate to convert the inputted greeting messages in 
to a user selected language.
