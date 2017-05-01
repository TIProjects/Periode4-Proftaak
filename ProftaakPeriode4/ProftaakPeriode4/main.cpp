<<<<<<< HEAD
<<<<<<< HEAD
#include "main.h"
#include "iostream"

=======
>>>>>>> c09da0191b9424f5c30fa2cc4af424414086e7af
int main() {
	std::cout << "Test" << std::endl;
	getchar();
=======
#include "Model.h"
#include "View.h"

int main() {
	Model model = Model();
	View view = View(model);
>>>>>>> a3198cc4071857c9e7fe7c62ec4ec05b54623359
	return 0;
}