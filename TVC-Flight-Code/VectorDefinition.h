struct Vector3 {
  float x, y, z;
  Vector3(float x, float y, float z): x{x}, y{y}, z{z} {}
  Vector3(): x(0), y(0), z(0) {}
  Vector3(sensors_vec_t vec): x{vec.x}, y{vec.y}, z{vec.z} {};
};
