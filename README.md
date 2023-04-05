# ScreenWriting
#The application simulates the writing of a television episode by professional screenwriters, as follows:

1. The information about the screenwriters working on the episode is in a text file. Each writer has a name, and his/her expertize - can be
  an assistant, junior or senior. This file is manually created and it is read when the application starts. 
  
2. Another file contains information about the ideas that were proposed by the writers. Each idea has a description, a status (can be proposed or accepted),
  the creator - the name of the writer who created it and the act (it only can be 1,2 or 3). These are read when the application starts.
  
3. When the application is launched, a new window is created for each writer, having as title the writer's name. The window will show all the ideas
  launched so far, sorted by act and creator.
  
4. Any writer can add a new idea, by inputting the idea's description and act and pressing the button "Add". The idea's creator will automatically
   be the name of the writer who added it and the status will be proposed. This operation fails if the description is empty, if the act is not 1,2 or 3
   or if there is another idea with the same description in the same act. The user will be informed if the operation fails.
   
5. An idea can be removed only if it is not accepted. Only senior writers can remove ideas.

6. Senior writers can revise ideas and accept them, by selecting the idea and pressing the button "Accept". This button is activated only if the 
   status of the selected idea is proposed. Whenever an idea is accepted, its status changes to accepted.

7. When a modification is made by any writer, all the other writers will see the modified list of ideas.

8. Each writer has a "Save plot" button which wil save to a file the entire plot of the episode: this will contain only the accepted ideas,
   their writers and will be created by acts: all ideas from act 1,on separate line;Act 2,the same;Act 3, the same.
   
