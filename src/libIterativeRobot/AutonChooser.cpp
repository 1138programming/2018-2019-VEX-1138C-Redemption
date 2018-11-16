#include "AutonChooser.h"

size_t AutonChooser::numAutons;
std::vector<const char*> AutonChooser::autonNames;
size_t AutonChooser::auton;

// LVGL Objects
lv_obj_t* AutonChooser::scrollLeft = NULL;
lv_obj_t* AutonChooser::autonName = NULL;
lv_obj_t* AutonChooser::scrollRight = NULL;

AutonChooser* AutonChooser::instance;

AutonChooser::AutonChooser() {
  auton = 0;

  autonNames.push_back("Red Auton\0");
  autonNames.push_back("Blue Auton\0");

  numAutons = autonNames.size();
}

lv_res_t AutonChooser::updateAutonName(lv_obj_t* btn) {
  if (btn == scrollRight) {
    if (auton >= numAutons - 1)
      auton = 0;
    else
      auton++;
  } else if (btn == scrollLeft) {
    if (auton <= 0)
      auton = numAutons - 1;
    else
      auton--;
  }
  printf("Auton is %d, size is %d\n", auton, autonNames.size());
  pros::delay(1000);
  lv_label_set_text(autonName, autonNames[auton]);
  return LV_RES_OK;
}

void AutonChooser::init() {
  if (scrollRight == NULL) {
    scrollRight = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_t* scrollRightLabel = lv_label_create(scrollRight, NULL);
    lv_label_set_text(scrollRightLabel, ">");
    lv_btn_set_action(scrollRight, LV_BTN_ACTION_PR, updateAutonName);
    lv_obj_align(scrollRight, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);

    autonName = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(autonName, autonNames[auton]);
    lv_obj_align(autonName, NULL, LV_ALIGN_CENTER, 0, 0);

    scrollLeft = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_t* scrollLeftLabel = lv_label_create(scrollLeft, NULL);
    lv_label_set_text(scrollLeftLabel, "<");
    lv_btn_set_action(scrollLeft, LV_BTN_ACTION_PR, updateAutonName);
    lv_obj_align(scrollLeft, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);
  }
}

void AutonChooser::uninit() {
  if (scrollRight != NULL) {
    lv_obj_del(scrollRight);
    lv_obj_del(autonName);
    lv_obj_del(scrollLeft);

    scrollRight = NULL;
    autonName = NULL;
    scrollLeft = NULL;
  }
}

size_t AutonChooser::getAutonChoice() {
  return auton;
}

AutonChooser* AutonChooser::getInstance() {
  if (instance == 0) {
    instance = new AutonChooser();
  } else {
    return instance;
  }
}
