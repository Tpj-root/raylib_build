# raylib_notes


**SITE**

https://www.raylib.com/cheatsheet/cheatsheet.html



# structs


**normal**


```
#include <stdio.h>

typedef struct Vector2 {
    float x;
    float y;
} Vector2;

int main() {
    Vector2 position = {400, 300};

    printf("Vector2 Position: x = %.2f, y = %.2f\n", position.x, position.y);

    return 0;
}

```



**struct Vector2;**
**struct Vector3;**
**struct Vector4;**
```
#include "raylib.h"
#include <stdio.h>

int main() {
    Vector2 position = {400, 300}; // Define a Vector2
    Vector3 v3 = {1.0f, 2.0f, 3.0f};     // 3D vector
    Vector4 v4 = {1.0f, 2.0f, 3.0f, 4.0f}; // 4D vector

    printf("Vector2 Position: x = %.2f, y = %.2f\n", position.x, position.y);
    printf("Vector3: x = %.2f, y = %.2f, z = %.2f\n", v3.x, v3.y, v3.z);
    printf("Vector4: x = %.2f, y = %.2f, z = %.2f, w = %.2f\n", v4.x, v4.y, v4.z, v4.w);

    return 0;
}

```


```
https://github.com/raysan5/raylib/blob/c647d337034585251d3d76d32093ac88a4c4ab82/src/raylib.h#L228
```


Memory Usage:

    float takes 4 bytes per component, while double takes 8 bytes.
    Using double would increase memory usage and slow down performance.



Data Type	Size (Bytes)	Range
int	4 bytes	-2,147,483,648 to 2,147,483,647
float	4 bytes	~ ±3.4 × 10³⁸ (7 decimal places)
double	8 bytes	~ ±1.8 × 10³⁰⁸ (15-16 decimal places)



Precision

    int can only store whole numbers (e.g., 1, 2, 3, …), which is bad for smooth movement.
    float supports decimals (e.g., 1.5, 2.75), making animations and physics smooth.

Graphics & GPU Compatibility

    Most graphics libraries (OpenGL, Vulkan, DirectX) use float for positions, rotations, etc.

Same Memory Size, More Flexibility

    int and float both take 4 bytes, but float is better for graphics.
    
    
    
    
The compiler automatically treats 1 as 1.0f, 2 as 2.0f, and 3 as 3.0f.    
Best Practice
Vector3 v3 = {1.0f, 2.0f, 3.0f};  // Explicit float values









```
#include "raylib.h"
#include <stdio.h>


#define PI 3.141



#ifndef PI
    #define PI 3.14159265358979323846f
#endif
#ifndef DEG2RAD
    #define DEG2RAD (PI / 180.0f)
#endif
#ifndef RAD2DEG
    #define RAD2DEG (180.0f / PI)
#endif


    float degrees = 90.0f;
    float radians = degrees * DEG2RAD;  // Convert 90° to radians
    float backToDegrees = radians * RAD2DEG;  // Convert back to degrees

    printf("Degrees: %.2f\n", degrees);
    printf("Radians: %.6f\n", radians);
    printf("Back to Degrees: %.2f\n", backToDegrees);
    
```




**camera**


```
https://www.youtube.com/watch?v=RlSpjIb7TLo&ab_channel=DevWorm

```





Right-handed: If you point your right-hand thumb in the +Z direction, curling your fingers shows +X to the right and +Y up.
Used in OpenGL.
DirectX uses a left-handed system (Z-axis flipped).



Column-major means data is stored column-by-column (used in OpenGL).
Row-major means data is stored row-by-row (used in DirectX).




Usage in 3D Transformations

A 4x4 matrix is used for:

    Translation (Move object)
    Rotation (Spin object)
    Scaling (Resize object)
    Perspective Projection
    
    

```

Matrix translationMatrix = {
    1, 0, 0, 5,  // Move 5 units in X
    0, 1, 0, 2,  // Move 2 units in Y
    0, 0, 1, -3, // Move -3 units in Z
    0, 0, 0, 1
};



```



**`module: rtextures:`**

![](img/Basic_0.png)






**module: rtextures **


void ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color);

// Draw text (using default font) within an image (destination)


DrawText("Free camera default controls:", 20, 20, 10, BLACK);























