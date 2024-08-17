#!/usr/bin/env /usr/bin/python3

import rospy
from geometry_msgs.msg import Twist
import sys, select, termios, tty
import serial

# Inisialisasi
rospy.init_node('teleop_key_low_control')
pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
msg = Twist()

# Konfigurasi port serial
ser = serial.Serial('/dev/ttyUSB1', 9600, timeout=1)

# Fungsi untuk membaca input keyboard
def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

# Fungsi utama
def teleop():
    global settings
    settings = termios.tcgetattr(sys.stdin)
    rospy.loginfo("-==========================================================================-")
    rospy.loginfo("-=====================Teleop Node Low Conntrol============-================-")
    rospy.loginfo("-==========================================================================-")

    while not rospy.is_shutdown():
        key = getKey()
        msg.linear.x = 0.0
        msg.linear.y = 0.0
        msg.linear.z = 0.0
        l = 0.0 
        if key == '\x03' or key == 'l': # Ctrl-C or q to exit
            break

        elif key == 'w':
            msg.linear.x = 0.0
            msg.linear.y = 15
            msg.linear.z = 0.0
            
       
        elif key == 's':
            msg.linear.x = 0.0
            msg.linear.y = -15
            msg.linear.z = 0.0
            
       
        elif key == 'a':
            msg.linear.x = -15
            msg.linear.y = 0.0
            msg.linear.z = 0
            
       
        elif key == 'd':
            msg.linear.x = 15
            msg.linear.y = 0.0
            msg.linear.z = 0
            
       
        elif key == 'q':
            msg.linear.x = 0.0
            msg.linear.y = 0.0
            msg.linear.z = -1
            
       
        elif key == 'e':
            msg.linear.x = 0.0
            msg.linear.y = 0.0
            msg.linear.z = 1
            
       
        elif key == 'r':
            l = 50
            

        elif key == 'f':
            l = -50
    
        else :
            # If no key is pressed, set all values to 0
            msg.linear.x = 0.0
            msg.linear.y = 0.0
            msg.linear.z = 0.0
            l = 0.0

       

        pub.publish(msg)

        # Mengirim koordinat ke perangkat serial
        serial_msg = "{},{},{},{}\n".format(msg.linear.x, msg.linear.y, msg.linear.z , l)
        ser.write(serial_msg.encode())

    # Saat program berakhir, robot akan berhenti
    msg.linear.x = 0.0
    msg.linear.y = 0.0
    msg.linear.z = 0.0
    pub.publish(msg)

if __name__ == '__main__':
    try:
        teleop()
    except rospy.ROSInterruptException:
        pass
