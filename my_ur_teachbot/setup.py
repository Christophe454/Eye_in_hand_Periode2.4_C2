from setuptools import find_packages, setup

package_name = 'my_ur_teachbot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='gerard',
    maintainer_email='GerardAnneHarkema@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'teachbot_follower_moveit_commander = my_ur_teachbot.teachbot_follower_moveit_commander:main',
            'teachbot_follower_action = my_ur_teachbot.teachbot_follower_action:main',
        ],
    },
)
