from setuptools import setup

package_name = 'py_action_demo'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='chenying',
    maintainer_email='evshary@gmail.com',
    description='Simple Python Action Demo',
    license='BSD',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'fibonacci_action_server = py_action_demo.fibonacci_action_server:main',
            'fibonacci_action_client = py_action_demo.fibonacci_action_client:main',
        ],
    },
)
