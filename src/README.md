<H1 style="text-align: center;"> DFPAC: A Multithreaded C++ dataframe </H1> 

# Current State of The Project
## How to use:  
    You should compile the project using the Install_Test.sh script found in the project root. To add the dataframe to your project using g++ add '-lDataFrame' to your instructions (EX: g++ ./Test_DF/Test_DF.cpp -lDataFrame -o ./Test_DF/test.out). If you cannot use the bashscript, follow along with the makefile found in this folder and try to translate it and add the headers and output library to your project manually. If you need help feel free to reach out.
## Structure of project: 
### Dataframe
    This object holds the code needed for reading new entries as well as some basic ways to interact with entries. Data is stored in a vector of DataFrameRow objects. The Dataframe object contains a private member DefaultRow that contains the template that all future rows are made from. This allows new data entry to be fast, but comes with some restrictions. The main one is that each column can only contain the same type of data. When you initialize a new dataframe, you must know ahead of time what type of data is being stored. Currently only floats, string, and discrete values can be stored. To learn how to create new types to add to the dataframe, read the section on NodeValue. Currently working on adding multithreading to some opeartions, namely sorting, reducing, and whole dataframe alterations. Also looking into adding GPU support.
### DataFrameRow
    The dataframe row contains code to create new rows of the same structure, and to grab values based on column index or column title. Each row contains a pointer to a global dictionary of column titles and indexs. 
### NodeValue
    Each node value type is an implimentation of the virtual class NodeValue. Currently 3 types have been implimented, DPFloat, DPString, and DPDiscrete. To create a new type you must impliment all of the virtual functions in NodeValue, which consists of a lot of copy paste. To make this process easier there is a python script in the ~/extras folder called GenerateNewNodeValue.py which will create empty functions, and both the .h and .cpp files to impliment the NodeValue object. Once you have filled in the rest, you can either place both files in the DFPAC folder and modify the makefile to compile with the rest of the library, or place them with your main project. The goal of this format is to impliment something close to dynamic type checking in c++, without sacraficing too much performance. Both DPString and DPFloat are fairly obvious, but DPDiscrete is slightly unique. This value stores both an integer, and a pointer to a hashtable shared amungst all discrete nodes in a column. This greatly reduces memory usage and comparison and sorting operations, with a little bit of a tradeoff for new data entry time. Each Nodevalue has methods to create a node of the same type.