import roboticstoolbox as rtb
from spatialmath import SE3
import numpy as np

robot = rtb.models.px100()

tx = 0.2486
ty = 0.0
tz = 0.193
tpos = SE3(tx, ty, tz)

# robot[11] is the index of ee_gripper_link in the urdf
ik_sol = robot.ikine_LM(tpos, end=robot[11])

if ik_sol.success:
    print("Valid Solution: {}".format(ik_sol.q))
    # Uncomment the following lines to validate the solution
    # print("FK Validation:")
    # fk_val = robot.fkine(np.array( [0, 0, 0, 0] ), end=robot[11], start=robot[0])
    # print(fk_val.t)
else:
    print("Invalid Input!!!")
