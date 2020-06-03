#include <exception>

class MatrixSize : public std::exception {

   public:
   virtual const char* what() const throw() {
	   return "Matrix sizes are different";
   }
};

class DoNotHaveInverseError : public std::exception {

   public:
   virtual const char* what() const throw() {
	   return "This matrix does not have an inverse.";
   }
};
