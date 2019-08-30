node {
   checkout scm
   stage('Build') {
      // Run the build
      sh '''
      python3 -m venv venv
      . venv/bin/activate
      pip install -r requirements.txt
      python setup.py build_ext --inplace
      pip install -e .
      pip install pytest pytest-cov
      '''
   }
   stage('Test') {
   sh '''
    . venv/bin/activate
    pip install pytest pytest-cov pytest-azurepipelines
    python -m pytest --doctest-modules example --cov=example --cov-report=xml
    ''' 
   }
   stage('Build Documentation') {
   sh '''
    . venv/bin/activate
    pip install sphinx
    python -m sphinx docs docs/html
    ''' 
   }
   stage('Results') {
      junit '**/*.xml'
      archive 'target/*.jar'
   }
}