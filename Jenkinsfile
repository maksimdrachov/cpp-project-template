pipeline {
    agent {
        docker { image 'maksimdrachov/ubuntu-cpp:latest' }
    }
    triggers {
        pollSCM '* * * * *'
    }
    stages {
        stage('Build') {
            steps {
                echo "....Building...."
                sh '''
                cmake --version
                valgrind --version
                rm -rf build
                mkdir build
		        cd build
		        cmake ..
		        cmake --build . --target main
                cd app
                ./main 6 3
                '''
            }
        }

        stage('Static analysis') {
            steps {
                echo "....clang-tidy..."
                sh '''
                cd build
                rm CMakeCache.txt
                cmake -DENABLE_CLANG_TIDY=ON ..
                cmake --build . --target main
                '''
            }
        }

        stage('Valgrind check') {
            steps {
                echo "....Valgrind...."
                sh '''
                cd build/app
                valgrind --leak-check=yes ./main 6 3
                valgrind --leak-check=yes ./main 6 4
                '''
            }
        }

        stage('Unit tests') {
            steps {
                echo "....Unit test...."
                sh '''
                cd build
                rm CMakeCache.txt
                cmake -DENABLE_TESTING=ON ..
                cmake --build . --target unit_tests
                cd tests
                ./unit_tests
                '''
            }
        }

        stage('Code coverage') {
            steps {
                echo "....Code Coverage...."
                sh '''
                cd build
                rm CMakeCache.txt
                cmake -DENABLE_TESTING=ON -DENABLE_COVERAGE -DCMAKE_BUILD_TYPE=Debug ..
                cmake --build . --target coverage
                '''
            }
        }

        stage('Style') {
            steps {
                echo "....clang-format...."
                sh '''
                cd build
                rm CMakeCache.txt
                cmake -DENABLE_CLANG_FORMAT=ON ..
                cmake --build . --target clang-format-check
                '''
            }
        }

        stage('Running') {
            steps {
                echo '....Running....'
                sh '''
		        cd build/app
		        ./main 5 3
                '''
            }
        }
    }
}
