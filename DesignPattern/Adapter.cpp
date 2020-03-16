#include <iostream>
#include<string>
#include "./Adapter.h"



Banner::Banner(std::string string) {
    this->string = string;
}


void Banner::showWithParen() {
    std::cout << "(" << string << ")" << std::endl;
}

void Banner::showWitAster() {
    std::cout << "*" << string << "*" << std::endl;
}

void PrintBanner::printWeak() {
    showWithParen();
}

void PrintBanner::printStrong() {
    showWitAster();
}


PrintBannerDeligation::PrintBannerDeligation(std::string string) {
    this->banner = new Banner(string);
}


void PrintBannerDeligation::printWeak() {
    banner->showWithParen();
}

void PrintBannerDeligation::printStrong() {
    banner->showWitAster();
}