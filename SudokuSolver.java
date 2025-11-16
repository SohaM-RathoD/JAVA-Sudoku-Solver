public class SudokuSolver {

    public static boolean isValid(int[][] board, int row, int col, int num) {

        // Row check
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) {
                return false;
            }
        }

        // Column check
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) {
                return false;
            }
        }

        // 3x3 box check
        int sr = row - row % 3;
        int sc = col - col % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[sr + i][sc + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    public static boolean Solver(int[][] board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == 0) {

                    for (int num = 1; num <= 9; num++) {

                        if (isValid(board, row, col, num)) {

                            board[row][col] = num;

                            if (Solver(board)) {
                                return true;
                            }

                            board[row][col] = 0; // backtrack
                        }
                    }

                    return false;  // no number fits → dead end
                }

            }
        }

        return true; // no empty cell left → solved
    }

    public static void printboard(int[][] board) {
        for (int h = 0; h < 9; h++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[h][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] board = {
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
        };

        if (Solver(board)) {
            printboard(board);
        } else {
            System.out.println("NO Solution Exists");
        }
    }
}
