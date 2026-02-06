#include <iostream>
#include <string>
#include <limits>

struct DuctSizes {
    std::string roundDuct;
    std::string rectangularDuct;
    bool inRange = true;
};

// Reads a positive double with validation (no crashes on bad input)
double readPositiveDouble(const std::string& prompt) {
    double value;

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin.fail() && value > 0.0) {
            // Clear the rest of the line (if any)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        std::cout << "  [Error] Enter a positive number (e.g., 250).\n";
        std::cin.clear(); // clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
    }
}


DuctSizes getSupplyDuctSizes_0p10(double airflowCFM) {
    DuctSizes sizes;

    // Table is defined up to 4000 CFM in this version
    if (airflowCFM > 4000) {
        sizes.inRange = false;
        return sizes;
    }

    // Determine duct sizes based on airflow (Supply @ 0.10 in.w.g./100 ft)
    if (airflowCFM <= 50) {
        sizes.roundDuct = "5\"";
        sizes.rectangularDuct = "6x4";
    }
    else if (airflowCFM <= 75) {
        sizes.roundDuct = "6\"";
        sizes.rectangularDuct = "6x4";
    }
    else if (airflowCFM <= 100) {
        sizes.roundDuct = "6\"";
        sizes.rectangularDuct = "6x6 or 8x4";
    }
    else if (airflowCFM <= 125) {
        sizes.roundDuct = "7\"";
        sizes.rectangularDuct = "8x6 or 10x4";
    }
    else if (airflowCFM <= 150) {
        sizes.roundDuct = "7\"";
        sizes.rectangularDuct = "8x6 or 10x4";
    }
    else if (airflowCFM <= 175) {
        sizes.roundDuct = "8\"";
        sizes.rectangularDuct = "8x6 or 12x4";
    }
    else if (airflowCFM <= 200) {
        sizes.roundDuct = "8\"";
        sizes.rectangularDuct = "8x6 or 14x4";
    }
    else if (airflowCFM <= 250) {
        sizes.roundDuct = "9\"";
        sizes.rectangularDuct = "10x6 or 16x4";
    }
    else if (airflowCFM <= 300) {
        sizes.roundDuct = "9\"";
        sizes.rectangularDuct = "10x8 or 12x6";
    }
    else if (airflowCFM <= 350) {
        sizes.roundDuct = "10\"";
        sizes.rectangularDuct = "10x8 or 14x6";
    }
    else if (airflowCFM <= 400) {
        sizes.roundDuct = "10\"";
        sizes.rectangularDuct = "10x8 or 14x6";
    }
    else if (airflowCFM <= 500) {
        sizes.roundDuct = "12\"";
        sizes.rectangularDuct = "12x8 or 18x6";
    }
    else if (airflowCFM <= 600) {
        sizes.roundDuct = "12\"";
        sizes.rectangularDuct = "12x10 or 14x8 or 20x6";
    }
    else if (airflowCFM <= 700) {
        sizes.roundDuct = "12\"";
        sizes.rectangularDuct = "12x10 or 16x8 or 22x6";
    }
    else if (airflowCFM <= 800) {
        sizes.roundDuct = "14\"";
        sizes.rectangularDuct = "14x10 or 18x8 or 26x6";
    }
    else if (airflowCFM <= 900) {
        sizes.roundDuct = "14\"";
        sizes.rectangularDuct = "14x12 or 16x10 or 20x8";
    }
    else if (airflowCFM <= 1000) {
        sizes.roundDuct = "14\"";
        sizes.rectangularDuct = "14x12 or 16x10 or 22x8";
    }
    else if (airflowCFM <= 1200) {
        sizes.roundDuct = "16\"";
        sizes.rectangularDuct = "16x12 or 20x10";
    }
    else if (airflowCFM <= 1600) {
        sizes.roundDuct = "18\"";
        sizes.rectangularDuct = "18x14 or 20x12";
    }
    else if (airflowCFM <= 2000) {
        sizes.roundDuct = "18\"";
        sizes.rectangularDuct = "18x14 or 22x12";
    }
    else if (airflowCFM <= 2500) {
        sizes.roundDuct = "20\"";
        sizes.rectangularDuct = "20x16 or 24x14";
    }
    else if (airflowCFM <= 3500) {
        sizes.roundDuct = "22\"";
        sizes.rectangularDuct = "22x18 or 24x16";
    }
    else { // <= 4000
        sizes.roundDuct = "24\"";
        sizes.rectangularDuct = "24x20 or 26x18";
    }

    return sizes;
}

int main() {
    std::cout << "SUPPLY AIR DUCT SIZER (Design: 0.10 in.w.g./100 ft)\n";
    std::cout << "---------------------------------------------------\n\n";

    while (true) {
        double airflow = readPositiveDouble("Enter Supply Airflow (CFM): ");

        DuctSizes sizes = getSupplyDuctSizes_0p10(airflow);

        std::cout << "\nResult (Supply @ 0.10 in.w.g./100 ft)\n";
        std::cout << "  Airflow: " << airflow << " CFM\n";

        if (!sizes.inRange) {
            std::cout << "  Out of range—extend table.\n\n";
        }
        else {
            std::cout << "  Round Duct: " << sizes.roundDuct << "\n";
            std::cout << "  Rect Duct : " << sizes.rectangularDuct << "\n\n";
        }

        std::cout << "\n";
    }

    std::cout << "\nDone.\n";
    return 0;
}
