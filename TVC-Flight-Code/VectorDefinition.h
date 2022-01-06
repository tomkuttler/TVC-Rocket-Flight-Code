/*
 * Vector definitions
 * 
 * Standard maths definitions
 */

struct Vector3 {
  float x, y, z;
  Vector3(float x, float y, float z): x{x}, y{y}, z{z} {}
  Vector3(): x(0), y(0), z(0) {}
  Vector3(sensors_vec_t vec): x{vec.x}, y{vec.y}, z{vec.z} {};

  // Multiply vector with float
  Vector3 operator * (float d) {
    Vector3 P;
    P.x = x * d;
    P.y = y * d;
    P.z = z * d;
    return P;
  }

  // Integrate vector
  Vector3 * operator += (Vector3 Vector) {
    x += Vector.x;
    y += Vector.y;
    z += Vector.z;
    return this;
  }
};
