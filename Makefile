CXX = g++
CXXFLAGS = -std=c++11

app: app.o secretary.o person.o course.o student.o professor.o menu_functions.o semester.o
	$(CXX) $(CXXFLAGS) -o app app.o secretary.o person.o course.o student.o professor.o menu_functions.o semester.o

app.o: app.cpp secretary.h person.h menu_functions.h
	$(CXX) $(CXXFLAGS) -c app.cpp

secretary.o: secretary.cpp secretary.h person.h
	$(CXX) $(CXXFLAGS) -c secretary.cpp

person.o: person.cpp person.h
	$(CXX) $(CXXFLAGS) -c person.cpp

course.o: course.cpp course.h person.h
	$(CXX) $(CXXFLAGS) -c course.cpp

student.o: student.cpp student.h person.h course.h
	$(CXX) $(CXXFLAGS) -c student.cpp

professor.o: professor.cpp professor.h person.h course.h
	$(CXX) $(CXXFLAGS) -c professor.cpp

menu_functions.o: menu_functions.cpp menu_functions.h secretary.h person.h course.h student.h professor.h
	$(CXX) $(CXXFLAGS) -c menu_functions.cpp

semester.o: semester.cpp semester.h course.h student.h
	$(CXX) $(CXXFLAGS) -c semester.cpp

run: app
	./app

valgrind: app
	valgrind --leak-check=full ./app

clean:
	rm -f *.o app
