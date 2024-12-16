#include "mlx.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
    {
        return (1);
    }
    win = mlx_new_window(mlx, 800, 600, "Hello MiniLibX!");
    mlx_loop(mlx);
    return (0);
}