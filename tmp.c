int my_atoi(char *buffer)
{
    int k = 1, x = 0, n = 0;
    while (buffer[n]) {
        if (buffer[n] >= 48 && buffer[n] <= 57) {
            x *= 10;
            x += (buffer[n] - 48);
        } else
            return -1;
        n++;
    }
    return x;
}

int row(char *tempo)
{
    int i = 0;
    int count = 0;

    for (i = 0; tempo[i] != '\0'; i++) {
        if (tempo[i] == '\n') {
            count ++;
        }
    }
    return (count);
}

int count_cols(char *count)
{
    int a = 0;
    int j = 0;

    for (j = 0; count[j] != '\0'; j++) {
        a++;
    }
    return a;
}

int count_cellul(char **map, int x, int y) {
    int count = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < row(map) && j >= 0 && j < count_cols(map)) {
                if ((i != x || j != y) && map[i][j] == 'X') {
                    count++;
                }
            }
        }
    }
    return count;
}

int fonction_for_chekmap(char **map, int rows, int cols)
{
    char **map_sauv = NULL;
    int nb = 0;
    rows = row(map);
    cols = count_cols(map);

    map = malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        map[i] = malloc(sizeof(char *) * (cols + 1));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nb = count_cellul(map, i, j);
            if (map[i][j] == 'X' && (nb < 2 && nb > 3)) {
                map_sauv[i][j] = '.';
                continue;
            }
            if (map[i][j] == 'X' && nb ==  2) {
                map_sauv[i][j] = 'X';
                continue;
            }
            if (map[i][j] == 'X' && nb == 3) {
                map_sauv[i][j] = 'X';
                continue;
            }
            if (map[i][j] == '.' && (nb < 2 && nb > 3)) {
                map_sauv[i][j] = '.';
                continue;
            }
            if (map[i][j] == '.' && nb == 2) {
                map_sauv[i][j] = '.';
                continue;
            }
            if (map[i][j] == '.' && nb == 3) {
                map_sauv[i][j] = 'X';
                continue;
            }
            //map[i][j] = map_sauv[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            map[i][j] = map_sauv[i][j];
        }
    }
}

int display_map(char **map, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int itteration(char **map, int rows, int cols, int iter)
{
    for (int i = 0; i < iter; i++) {
        fonction_for_chekmap(map, rows, cols);
    }
    display_map(map, rows, cols);
}

int main(int argc, char **argv)
{
    char *file = read_fil(argv[1]);
    // char **map = string_array_mod(file, '\n');
    // int nb_ligne = row(file);
    // int nb_cols = count_cols(file);
    // int iter = my_atoi(argv[3]);

    printf(file);

    // itteration(map, nb_ligne, nb_cols, iter);

    // for(int i = 0; map[i] != NULL; i++) {
    //     printf("%s\n", map[i]);
    // }
}
