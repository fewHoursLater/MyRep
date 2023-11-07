In each task, a base class should be made that solves the problem. Let's call it CData. In each class, a [purely] virtual function should be created to output class data to a file of the form virtual int output(const char *FileName=NULL)=0; From this CData class it is necessary to generate two classes CData0 and CData1, in the first of which the function int output(const char *FileName) is redefined; as a function of outputting class data to a file in one row, and in the second this function is defined as a function of outputting class data to a column (i.e. one element at a time data in one line). In the source data file, data is set in each line for one instance of the class generated from CData. The task data is set in each line in the form: I FileName Data where I = 0 or = 1, FileName is the name of the output file, Data is all the data of one object, separated by spaces. For each line of the source file, you need to create a CData0 class if I == 0, or you need to create a CData1 class if I == 1. The created class must be filled with data from the entered string. The name of the output file should be entered in the corresponding field of the created class. All created classes should be placed in an array of pointers to the base class CData **arr;. Each new object must be created by a function of the form CData *CreateData(const char *str, CFabricData **f );. where f is an array of factories for creating the I—th child class from CData. Next, you need to call the output() function in a loop for each object from the arr array. You also need to write a reasonable test for all the implemented functions of the class.
