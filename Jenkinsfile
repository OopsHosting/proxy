pipeline {
    agent any

    stages {
        stage('CMake') {
            steps {
                echo 'CMaking...'
                cmake .
            }
        }
        stage('Make') {
            steps {
                echo 'Making...'
                make
            }
        }
    }
}
