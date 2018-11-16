#ifndef AUTONCHOOSER_H
#define AUTONCHOOSER_H

#include "main.h"
#include "display/lvgl.h"

#include <vector>

class AutonChooser {
  private:
    static size_t numAutons;
    static std::vector<const char*> autonNames;
    static size_t auton;

    // LVGL Objects
    static lv_obj_t* scrollLeft;
    static lv_obj_t* autonName;
    static lv_obj_t* scrollRight;

    AutonChooser();
    static AutonChooser* instance;
  public:
    static lv_res_t updateAutonName(lv_obj_t* btn);
    static void init();
    static void uninit();
    static size_t getAutonChoice();

    static AutonChooser* getInstance();
};

#endif
