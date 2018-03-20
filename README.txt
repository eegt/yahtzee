To get started with the Yahtzee project
----------------------------------------

1. In a command window, go to the directory where you want to store your local
   copy of this repository. (If you have a folder called 'github' or 'git' that
   holds all your git-tracked projects, go there.)

2. At the command prompt, enter

       $ git clone https://github.com/eegt/yahtzee.git

   to create a local copy of the repository.

3. Now you should have a new folder "yahtzee", and within that a few files
   plus subfolders "Yahtzee" and "YahtzeeTests". Browse to the folder
   /yahtzee/Yahtzee in your command window:

       $ cd yahtzee/Yahtzee

4. Run the build script called makeAndTest.sh:

       $ ./makeAndTest.sh

5. This script should have
       1) built the yahtzee project,
       2) built the unit test project that goes with it, and
       3) run the unit tests.

   If the build was successful, you're ready to create your own yahtzee player!



To create a player for the Yahtzee project
-------------------------------------------

1. Copy the player template.

   In the Yahtzee subfolder, Make copies of yahtzeePlayerTemplate.c and
   yahtzeePlayerTemplate.h. Rename your copies as yahtzeePlayerAlice.c/h or
   yahtzeePlayerBob.c/h or whatever.

2. Rename your play function.

   Open the two files you just created. In each, change the function name 
   PlayTemplate() to PlayAlice() or PlayBob() or PlayMyname() or whatever.

   Save both files.

3. Update your header file.

   a. In yahtzeePlayerMyname.h, change the #ifndef and #define to use
      yahtzeePlayerMyname_h instead of yahtzeePlayerTemplate.h.

   b. In yahtzeePlayMyname.c, change the #include from "yahtzeePlayerTemplate.h"
      to "yahtzeePlayerMyname.h".

   Save both files.

4. Do a quick band-aid fix to avoid a name conflict.

   In yahtzeePlayerMyname.c, change the function name DumbScore() to something
   different. DumbScore2(), DumberScore(), doesn't matter.

   You'll need to make the change 
      - in the function prototype near the top of the file,
      - in the function definition farther down, and 
      - where the function is called within PlayMyName()

   You should probably remove this function first thing when you start working
   on your own player... it's just a placeholder behavior to demonstrate returning
   valid results to the top-level program.

   Save the file.

5. Connect your new player to the top-level function.

   a. Open the file yahtzee.c. Near the top of the file, find the #include
      statements, and #include your new header:

      ...
      #include "yahtzeePlayerTemplate.h"   // <-- this is already here
      #include "yahtzeePlayerMyname.h"     // <-- add yours here
      ...

   b. Also near the top of the file, find the #define section. Increase the
      number of players by one:

      #define NPLAYERS 3    // <-- if this is 3, change it to 4

   c. Scroll down into the main() function and look for the section where
      the player function pointers are set up. Add your own function
      pointer at the bottom of that section. (The array index should be
      one less than the number of players you set in the previous section.)

      ...
      players[0].playFn = &PlayTemplate;  // <-- if this is already here
      players[1].playFn = &PlayAlice;     // <-- and this is already here
      players[2].playFn = &PlayBob;       // <-- and this is already here
      players[3].playFn = &playMyname;    // <-- add this
      ...

   d. Save this file.

4. Run the build script again:

       $ ./makeAndTest.sh

   If the build was successful, you're ready to start updating your own yahtzee
   player!



Using the Yahtzee simulator
----------------------------

1. To run the program, type './yahtzee' at the prompt in the yahtzee/Yahtzee
   directory.


2. To update your own yahtzee player, Edit the file yahtzeePlayerMyname.c with
   your logic to re-roll dice and score your yahtzee game.

   The top-level file yahtzee.c prints out some information about each test run
   that may be useful in debugging. You can comment these out if they're not
   useful in your development workflow, or add your own debug messages. BUT,
   changes to yahtzee.c that are specific to your own project won't be pulled
   into master. If you want to commit changes to master in files other than your
   own player file, please use the commit comment to describe why the change is
   an improvement for everyone.

   Note: Make sure you don't change the function signature of the PlayMyname()
   function (keep the same parameters and return type). But you can change
   the contents of that function, create subroutines, etc. to play the
   yahtzee game and fill in the score structure in an intelligent way.

   During development, if you want to build without running the unit tests each
   time, you can just do 'make' from within the yahtzee/Yahtzee folder, instead
   of running the makeAndTest.sh shell script each time.



