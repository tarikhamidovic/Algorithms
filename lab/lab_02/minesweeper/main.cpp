#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

bool push_unique(std::vector<int>& elements, int element) {
  // TODO make it unique, use std::find
  elements.push_back(element);
  return true;
}

class Field {
  private:
  int val_ = 0;
  bool covered_ = true;

  public:
  void uncover() { covered_ = false; }
  bool is_bomb() const { return val_ >= 100; }
  void increment() { val_ += 1; }
  bool covered() const { return covered_; }
  void set_bomb() { val_ = 100; }
  int value() const { return val_; }

  friend std::ostream& operator<<(std::ostream& out, const Field& f);
};

std::ostream& operator<<(std::ostream& out, const Field& f) {
  if (f.covered()) {
    return out << "XX";
  }
  if (f.val_ >= 100) out << " *";
  else if (f.val_ == 0) out << "  ";
  else out << " " << f.val_;
  return out;
}

class Playground {
  private:
  std::vector<std::vector<Field>> terrain_;

  void place_bomb(int bomb_x, int bomb_y) {
    terrain_[bomb_x][bomb_y].set_bomb();
    if (bomb_x > 0 && bomb_y > 0) terrain_[bomb_x - 1][bomb_y - 1].increment();
    if (bomb_x < 9 && bomb_y < 9) terrain_[bomb_x + 1][bomb_y + 1].increment();
    if (bomb_x > 0 && bomb_y < 9) terrain_[bomb_x - 1][bomb_y + 1].increment();
    if (bomb_x < 9 && bomb_y > 0) terrain_[bomb_x + 1][bomb_y - 1].increment();
    if (bomb_x > 0) terrain_[bomb_x - 1][bomb_y].increment();
    if (bomb_x < 9) terrain_[bomb_x + 1][bomb_y].increment();
    if (bomb_y < 9) terrain_[bomb_x][bomb_y + 1].increment();
    if (bomb_y > 0) terrain_[bomb_x][bomb_y - 1].increment();
  }

  public:
  Playground() {
    terrain_.resize(10);
    for (auto& row : terrain_) {
      row.resize(10);
    }
    // set bombs randomly
    std::vector<int> bombs;
    while (bombs.size() < 10) {
      push_unique(bombs, rand() % 100);
    }
    for (const auto& bomb : bombs) {
      place_bomb(bomb / 10, bomb % 10);
    }
  }

  bool open_field(int x, int y) {
    auto& f = terrain_[x][y];
    f.uncover();
    if (f.is_bomb()) {
      return true;
    }
    // if (f.value() == 0) {
    // TODO if val_ is zero, uncover all neighboring zero fields.
    // }
    return false;
  }

  friend std::ostream& operator<<(std::ostream& out, const Playground& playground);
};

std::ostream& operator<<(std::ostream& out,
                         const Playground& playground) {
  out << "______________________" << std::endl;
  for (const auto& row : playground.terrain_) {
    out << "|";
    for (const auto& column : row) {
      out << column;
    }
    out << '|' << std::endl;
  }
  out << "______________________" << std::endl;
  return out;
}


int main() {
  srand(clock());

  Playground playground;
  std::cout << playground << std::endl;

  int x;
  int y;
  while (std::cin >> x >> y) {
    std::cout << "Opening " << x << ", " << y << std::endl;
    auto bomb = playground.open_field(x, y);
    std::cout << playground << std::endl;
    if (bomb) {
      std::cout << "You loose!" << std::endl;
      break;
    }
  }
}
