# Doddle-Jump
Game written in C++ &amp; SFML
Version of "Doodle Jump" game.

1. Download SFML 2.5.1 from this link https://www.sfml-dev.org/download/sfml/2.5.1/
2. Put SFML on path: C:\SFML-2.5.1
3. Open project, in project properties set:
        - C/C++ / General (All Configurations)- Additional Include Directories : C:\SFML-2.5.1\include
        - Linker/General (All Congifurations) - Additional Library Directories: C:\SFML-2.5.1\lib
        - Linker/Input (Debug) -Additional Dependencies : sfml-graphics-d.lib 
                                                          sfml-window-d.lib
                                                          sfml-system-d.lib
                                                          sfml-network-d.lib
                                                          sfml-audio-d.lib
         - Linker/Input (Release) -Additional Dependencies : sfml-graphics.lib
                                                             sfml-window.lib
                                                             sfml-system.lib
                                                             sfml-network.lib
                                                             sfml-audio.lib
                                                             

Game loop
<br/>
<img src="https://user-images.githubusercontent.com/56079123/73777994-bb339400-478a-11ea-8851-51baccc0897e.png">

Start screen
<br/>
<img src="https://user-images.githubusercontent.com/56079123/73777901-90494000-478a-11ea-9671-404bca0dfdbb.png">

