#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <iostream>

int main() {
    std::cout << "dlib is installed and working!" << std::endl;
    dlib::image_window win;
    win.wait_until_closed();
    return 0;
}
