objects = beginner_work.o Stu_function.o grade_functions.o \
	average.o median.o
edit : $(objects)
	cc -o edit $(objects)
beginner_work.o : beginner_work.cpp  grade.h  Student_info.h
	cc -c beginner_work.cpp
Stu_function.o : Stu_function.cpp Student_info.h
	cc -c Stu_function.cpp
grade_functions.o : grade_functions.cpp  grade.h Student_info.h  \
   					   average.h  median.h
	cc -c grade_functions.cpp
average.o : average.cpp average.h
	cc -c average.cpp
median.o : median.cpp median.h
	cc -c median.cpp
.PHONY : clean
clean :
	rm edit $(objects)
