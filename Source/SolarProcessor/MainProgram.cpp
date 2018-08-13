#include "MainProgram.h"

using namespace SolarProcessor;             // sesuai nama proyek
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// buat form yang dirancang dan jalankan
	Application::Run(gcnew MainProgram());
	return 0;
}
