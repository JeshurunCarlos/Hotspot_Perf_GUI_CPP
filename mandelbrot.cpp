#include <complex>
#include <iostream>
#include <vector>

int mandelbrot(double x, double y) {
    std::complex<double> c(x, y);
    std::complex<double> z(0, 0);
    for (int i = 0; i < 1000; ++i) {
        z = z * z + c;
        if (std::norm(z) > 4) return i;
    }
    return 1000;
}

int main() {
    const int width = 800, height = 600;
    std::vector<int> image(width * height);
    for (int py = 0; py < height; ++py) {
        for (int px = 0; px < width; ++px) {
            double x = (px - width / 2.0) / 100;
            double y = (py - height / 2.0) / 100;
            image[py * width + px] = mandelbrot(x, y);
        }
    }
    std::cout << "Done\n";
    return 0;
}
