class Solution {
public:
    void setZeroes(vector<vector<int>>& mat ) {
        
        // STORE NUMBER OF ROWS

        int rows = mat.size();

        // STORE NUMBER OF COLUMNS

        int cols = mat[ 0 ].size();

        // FLAGS TO CHECK FIRST ROW AND COLUMN

        bool fcol = false;

        bool frow = false;


        // CHECK IF THERE IS A ZERO IN THE FIRST COLUMN

        for( int i = 0; i < rows; i++ ) {

            // SET FCOL TO TRUE IF ZERO IS FOUND

            if( mat[ i ][ 0 ] == 0 ) {

                fcol = true;

                break;
            }
        }

        // CHECK IF THERE IS A ZERO IN THE FIRST ROW

        for( int i = 0; i < cols; i++ ) {

            // SET FROW TO TRUE IF ZERO IS FOUND

            if( mat[ 0 ][ i ] == 0 ) {

                frow = true;

                break;
            }
        }

        // CHECK OTHER ELEMENTS IN THE MATRIX ( EXCLUDING FIRST ROW AND COLUMN)

        for( int i = 1; i < rows; i++ ) {

            for( int j = 1; j < cols; j++ ) {

                // IF ZERO IS FOUND, SET THE FIRST ELEMENT OF THAT ROW AND COLUMN TO ZERO

                if( mat[ i ][ j ] == 0 ) {

                    mat[ 0 ][ j ] = 0;

                    mat[ i ][ 0 ] = 0;
                }
            }
        }

        // ZERO OUT ROWS BASED ON FIRST COLUMN VALUES ( EXCEPT THE FIRST ROW)

        for( int i = 1; i < rows; i++ ) {

            if( mat[ i ][ 0 ] == 0 ) {

                for( int j = 1; j < cols; j++ ){

                    mat[ i ][ j ] = 0;
                }
            }
        }

        // ZERO OUT COLUMNS BASED ON FIRST ROW VALUES ( EXCEPT THE FIRST COLUMN)

        for( int j = 1; j < cols; j++ ) {

            if( mat[ 0 ][ j ] == 0 ) {

                for( int i = 1; i < rows; i++ ) {

                    mat[ i ][ j ] = 0;
                }
            }
        }

        // ZERO OUT FIRST COLUMN IF FCOL IS TRUE

        if( fcol ) {

            for( int i = 0; i < rows; i++ ) {

                mat[ i ][ 0 ] = 0;
            }
        }

        // ZERO OUT THE FIRST ROW IF FROW IS TRUE

        if( frow ) {

            for( int j = 0; j < cols; j++ ) {

                mat[ 0 ][ j ] = 0;
            }
  
      }

      return ;
    }
};
