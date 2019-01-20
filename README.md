# Linux-File-System-with-C

This project is a homework of Operating Systems course of AGU.

In this HW, you are asked to implement an imaginary file system. User will be able to create, delete or edit a file or folder. Note that this operations will not actually create a folder or a file in your real file system. You will just need to implement a tree structure to pretend like you are performing user requests. Your linked list and tree structure might look like as below.

![file_system](https://raw.githubusercontent.com/mansurmuaz/Linux-File-System-with-C/master/file_system.png)

Blue boxes are folders, yellow boxes are files, Red arrows are pointers to the next item in the folder, Green arrows are pointers to the first child item in the folder. Note that there is no pointer to a parent in this design, but you can modify this design to comply it with your requirements. You must implement this structure using linked lists, pointers, structures and dynamic memory allocation in C.

Your folder or file structure would possibly have:

```C
char* name;
int numberOfItems;
int size;
int date;
struct Node* next;
struct Node* child;
```

## An example run

When we run your program, we should see an empty command line waiting for our command. Let’s assume your file-folder structure is empty at beginning (In your actual submission, you will start with a sample file-folder structure.). Then, suppose we enter a creating new directory command:
```
> mkdir courses
```

Then you should create a folder structure variable with necessary attributes. Then, if we call “ls”, you should list the files and folders inside the current folder like following:

```
> mkdir courses
> ls
0items 28 Sep 19:15 courses
>
```

Let’s create a file and list again:

```
> mkdir courses
> ls
0items 28 Sep 19:15 courses
> touch syllabus.txt
> ls
0items 28 Sep 19:15 courses
0B     28 Sep 19:20 syllabus.txt
>
```

Let’s enter some text to the file and do some more operations:

```
> mkdir courses
> ls
0items 28 Sep 19:15 courses
> touch syllabus.txt
> ls
0items 28 Sep 19:15 courses
0B     28 Sep 19:20 syllabus.txt
> edit syllabus.txt
Please enter some text to overwrite the file content:

This course starts at 14:10 on every Thursday.
> ls
0items 28 Sep 19:15 courses
46B    28 Sep 19:23 syllabus.txt
> mov syllabus.txt courses
> ls
1items 28 Sep 19:15 courses
> cd courses
> touch schedule.txt
> ls
46B    28 Sep 19:23 syllabus.txt
0B     28 Sep 19:26 schedule.txt
> pwd
/courses
> cdup
> ls 
1items 28 Sep 19:15 courses
> lsrecursive
1items 28 Sep 19:15 courses
|_46B    28 Sep 19:23 syllabus.txt
|_0B     28 Sep 19:26 schedule.txt
> rm courses
Do you really want to remove 2 files and 1 folders? (y/n) y
46 bytes are freed.
>
```

## Requirements

You will implement the following commands:

Command | Definition
--- | ---
`ls` | Lists the content of the current directory. It also displays number of items in a folder, file sizes, time of modification
`lsrecursive` | Lists the content of the current directory and all sub directories. It also displays number of items in a folder, file sizes, time of modification
`mkdir` | Creates a directory
`rm` | Removes a file or a folder with all of its content.
`mov` | Move a file or a folder into another folder. (you might only support child folders)
`pwd` | Show absolute path of the current directory
`cd` | Change directory
`cdup` | Change current directory to parent directory
`edit` | Overwrite content of a text file with the entered text
`touch` | 

---

+	Do not preallocate space. You need to create space when a new entry arrives (dynamic allocation, malloc).
+	Do not leave any empty space. When an entry is deleted, you need to remove it from your list.
+	The list should be a linked list.
+	For each functionality, you need to have a separate function. That is, your code will call ls function when ls is selected. Pass your list by reference (see call by reference)
+	Most importantly, your program must not have any memory leak. Check with valgrind.
+	Provide your Makefile as well. We will use it to compile your code from console.
+	Write a report and discuss about challenging parts of the HW. Which parts of the assignment was difficult for you? How did you tackle those difficulties? Also include your valgrind memory leak output.
+	First three people who submit a working code will be announced and get extra 10 points.
+	See the course syllabus for more details about grading and consequences of plagiarism.
+	Note:	Install 64bit Ubuntu on VirtualBox. Use Eclipse as your IDE. Codes written in Windows might not work on Ubuntu (different system calls).


---
## Valgring Report
Here you can find my codes valgring report.

```
==11180== HEAP SUMMARY:
==11180==     in use at exit: 0 bytes in 0 blocks
==11180==   total heap usage: 182 allocs, 182 frees, 10,723 bytes allocated
==11180==
==11180== All heap blocks were freed -- no leaks are possible
==11180==
==11180== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==11180== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
