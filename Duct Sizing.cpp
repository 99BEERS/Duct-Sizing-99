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
     if (airflowCFM <= 75) {
        sizes.roundDuct = "6\"";
        sizes.rectangularDuct = "6x6";
     }
     else if (airflowCFM <= 125) {
         sizes.roundDuct = "8\"";
         sizes.rectangularDuct = "8x8";
     }
    else if (airflowCFM <= 700) {
        sizes.roundDuct = "12\"";
        sizes.rectangularDuct = "12x12";
    }
    else if (airflowCFM <= 3500) {
        sizes.roundDuct = "22\"";
        sizes.rectangularDuct = "22x22";
    }
    else { // <= 4000
        sizes.roundDuct = "24\"";
        sizes.rectangularDuct = "24x24";
    }

    return sizes;
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
