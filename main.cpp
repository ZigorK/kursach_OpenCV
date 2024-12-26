#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    // Проверка аргументов
    if (argc < 3) {
        std::cout << "Использование: " << argv[0] << " <путь_к_изображению> <путь_к_результату> [коэффициент_яркости]" << std::endl;
        return 1;
    }

    std::string inputPath = argv[1];
    std::string outputPath = argv[2];
    double alpha = (argc > 3) ? std::stod(argv[3]) : 1.0; // Коэффициент яркости (по умолчанию 1.0)

    // Загрузка изображения
    cv::Mat image = cv::imread(inputPath);
    if (image.empty()) {
        std::cerr << "Не удалось загрузить изображение: " << inputPath << std::endl;
        return 1;
    }

    // Увеличение/уменьшение яркости
    cv::Mat result;
    image.convertTo(result, -1, alpha, 0); // alpha - коэффициент усиления яркости, beta = 0

    // Сохранение результата
    if (!cv::imwrite(outputPath, result)) {
        std::cerr << "Не удалось сохранить изображение: " << outputPath << std::endl;
        return 1;
    }

    std::cout << "Изображение успешно обработано и сохранено: " << outputPath << std::endl;
    return 0;
}
