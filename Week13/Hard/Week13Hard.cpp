#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif

    double x, y, z, thrust, angle, warp_factor;

    std::cout << "Enter initial coordinates (x, y, z): ";
    std::cin >> x >> y >> z;

    std::cout << "Enter thrust: ";
    std::cin >> thrust;

    std::cout << "Enter angle (in degrees): ";
    std::cin >> angle;

    std::cout << "Enter warp factor: ";
    std::cin >> warp_factor;

    if (warp_factor == 0) {
        std::cout << "Warp factor cannot be zero. Hyperspace jump aborted.\n";
        return 1;
    }

    double angle_radians = angle * (M_PI / 180.0);

    double new_x = (x + thrust * std::cos(angle_radians)) * warp_factor;
    double new_y = (y + thrust * std::sin(angle_radians)) * warp_factor;
    double new_z = z + (thrust / warp_factor);

    std::cout << "New coordinates after hyperspace jump:\n";
    std::cout << "x: " << new_x << "\n";
    std::cout << "y: " << new_y << "\n";
    std::cout << "z: " << new_z << "\n";

    return 0;
}