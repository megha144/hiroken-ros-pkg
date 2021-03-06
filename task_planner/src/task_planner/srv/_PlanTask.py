"""autogenerated by genpy from task_planner/PlanTaskRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import arm_navigation_msgs.msg
import geometry_msgs.msg
import std_msgs.msg

class PlanTaskRequest(genpy.Message):
  _md5sum = "99170af098dfcb0ae7b06f35caecb510"
  _type = "task_planner/PlanTaskRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
arm_navigation_msgs/CollisionObject[] objects

================================================================================
MSG: arm_navigation_msgs/CollisionObject
# a header, used for interpreting the poses
Header header

# the id of the object
string id

# The padding used for filtering points near the object.
# This does not affect collision checking for the object.  
# Set to negative to get zero padding.
float32 padding

#This contains what is to be done with the object
CollisionObjectOperation operation

#the shapes associated with the object
arm_navigation_msgs/Shape[] shapes

#the poses associated with the shapes - will be transformed using the header
geometry_msgs/Pose[] poses

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.secs: seconds (stamp_secs) since epoch
# * stamp.nsecs: nanoseconds since stamp_secs
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: arm_navigation_msgs/CollisionObjectOperation
#Puts the object into the environment
#or updates the object if already added
byte ADD=0

#Removes the object from the environment entirely
byte REMOVE=1

#Only valid within the context of a CollisionAttachedObject message
#Will be ignored if sent with an CollisionObject message
#Takes an attached object, detaches from the attached link
#But adds back in as regular object
byte DETACH_AND_ADD_AS_OBJECT=2

#Only valid within the context of a CollisionAttachedObject message
#Will be ignored if sent with an CollisionObject message
#Takes current object in the environment and removes it as
#a regular object
byte ATTACH_AND_REMOVE_AS_OBJECT=3

# Byte code for operation
byte operation

================================================================================
MSG: arm_navigation_msgs/Shape
byte SPHERE=0
byte BOX=1
byte CYLINDER=2
byte MESH=3

byte type


#### define sphere, box, cylinder ####
# the origin of each shape is considered at the shape's center

# for sphere
# radius := dimensions[0]

# for cylinder
# radius := dimensions[0]
# length := dimensions[1]
# the length is along the Z axis

# for box
# size_x := dimensions[0]
# size_y := dimensions[1]
# size_z := dimensions[2]
float64[] dimensions


#### define mesh ####

# list of triangles; triangle k is defined by tre vertices located
# at indices triangles[3k], triangles[3k+1], triangles[3k+2]
int32[] triangles
geometry_msgs/Point[] vertices

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of postion and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

"""
  __slots__ = ['objects']
  _slot_types = ['arm_navigation_msgs/CollisionObject[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       objects

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlanTaskRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.objects is None:
        self.objects = []
    else:
      self.objects = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        _v1 = val1.header
        buff.write(_struct_I.pack(_v1.seq))
        _v2 = _v1.stamp
        _x = _v2
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v1.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_struct_f.pack(val1.padding))
        _v3 = val1.operation
        buff.write(_struct_b.pack(_v3.operation))
        length = len(val1.shapes)
        buff.write(_struct_I.pack(length))
        for val2 in val1.shapes:
          buff.write(_struct_b.pack(val2.type))
          length = len(val2.dimensions)
          buff.write(_struct_I.pack(length))
          pattern = '<%sd'%length
          buff.write(struct.pack(pattern, *val2.dimensions))
          length = len(val2.triangles)
          buff.write(_struct_I.pack(length))
          pattern = '<%si'%length
          buff.write(struct.pack(pattern, *val2.triangles))
          length = len(val2.vertices)
          buff.write(_struct_I.pack(length))
          for val3 in val2.vertices:
            _x = val3
            buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        length = len(val1.poses)
        buff.write(_struct_I.pack(length))
        for val2 in val1.poses:
          _v4 = val2.position
          _x = _v4
          buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
          _v5 = val2.orientation
          _x = _v5
          buff.write(_struct_4d.pack(_x.x, _x.y, _x.z, _x.w))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.objects is None:
        self.objects = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = arm_navigation_msgs.msg.CollisionObject()
        _v6 = val1.header
        start = end
        end += 4
        (_v6.seq,) = _struct_I.unpack(str[start:end])
        _v7 = _v6.stamp
        _x = _v7
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v6.frame_id = str[start:end].decode('utf-8')
        else:
          _v6.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        start = end
        end += 4
        (val1.padding,) = _struct_f.unpack(str[start:end])
        _v8 = val1.operation
        start = end
        end += 1
        (_v8.operation,) = _struct_b.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.shapes = []
        for i in range(0, length):
          val2 = arm_navigation_msgs.msg.Shape()
          start = end
          end += 1
          (val2.type,) = _struct_b.unpack(str[start:end])
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          pattern = '<%sd'%length
          start = end
          end += struct.calcsize(pattern)
          val2.dimensions = struct.unpack(pattern, str[start:end])
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          pattern = '<%si'%length
          start = end
          end += struct.calcsize(pattern)
          val2.triangles = struct.unpack(pattern, str[start:end])
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          val2.vertices = []
          for i in range(0, length):
            val3 = geometry_msgs.msg.Point()
            _x = val3
            start = end
            end += 24
            (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
            val2.vertices.append(val3)
          val1.shapes.append(val2)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.poses = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Pose()
          _v9 = val2.position
          _x = _v9
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
          _v10 = val2.orientation
          _x = _v10
          start = end
          end += 32
          (_x.x, _x.y, _x.z, _x.w,) = _struct_4d.unpack(str[start:end])
          val1.poses.append(val2)
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.objects)
      buff.write(_struct_I.pack(length))
      for val1 in self.objects:
        _v11 = val1.header
        buff.write(_struct_I.pack(_v11.seq))
        _v12 = _v11.stamp
        _x = _v12
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v11.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1.id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_struct_f.pack(val1.padding))
        _v13 = val1.operation
        buff.write(_struct_b.pack(_v13.operation))
        length = len(val1.shapes)
        buff.write(_struct_I.pack(length))
        for val2 in val1.shapes:
          buff.write(_struct_b.pack(val2.type))
          length = len(val2.dimensions)
          buff.write(_struct_I.pack(length))
          pattern = '<%sd'%length
          buff.write(val2.dimensions.tostring())
          length = len(val2.triangles)
          buff.write(_struct_I.pack(length))
          pattern = '<%si'%length
          buff.write(val2.triangles.tostring())
          length = len(val2.vertices)
          buff.write(_struct_I.pack(length))
          for val3 in val2.vertices:
            _x = val3
            buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
        length = len(val1.poses)
        buff.write(_struct_I.pack(length))
        for val2 in val1.poses:
          _v14 = val2.position
          _x = _v14
          buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
          _v15 = val2.orientation
          _x = _v15
          buff.write(_struct_4d.pack(_x.x, _x.y, _x.z, _x.w))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.objects is None:
        self.objects = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.objects = []
      for i in range(0, length):
        val1 = arm_navigation_msgs.msg.CollisionObject()
        _v16 = val1.header
        start = end
        end += 4
        (_v16.seq,) = _struct_I.unpack(str[start:end])
        _v17 = _v16.stamp
        _x = _v17
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v16.frame_id = str[start:end].decode('utf-8')
        else:
          _v16.frame_id = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.id = str[start:end].decode('utf-8')
        else:
          val1.id = str[start:end]
        start = end
        end += 4
        (val1.padding,) = _struct_f.unpack(str[start:end])
        _v18 = val1.operation
        start = end
        end += 1
        (_v18.operation,) = _struct_b.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.shapes = []
        for i in range(0, length):
          val2 = arm_navigation_msgs.msg.Shape()
          start = end
          end += 1
          (val2.type,) = _struct_b.unpack(str[start:end])
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          pattern = '<%sd'%length
          start = end
          end += struct.calcsize(pattern)
          val2.dimensions = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          pattern = '<%si'%length
          start = end
          end += struct.calcsize(pattern)
          val2.triangles = numpy.frombuffer(str[start:end], dtype=numpy.int32, count=length)
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          val2.vertices = []
          for i in range(0, length):
            val3 = geometry_msgs.msg.Point()
            _x = val3
            start = end
            end += 24
            (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
            val2.vertices.append(val3)
          val1.shapes.append(val2)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.poses = []
        for i in range(0, length):
          val2 = geometry_msgs.msg.Pose()
          _v19 = val2.position
          _x = _v19
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
          _v20 = val2.orientation
          _x = _v20
          start = end
          end += 32
          (_x.x, _x.y, _x.z, _x.w,) = _struct_4d.unpack(str[start:end])
          val1.poses.append(val2)
        self.objects.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_b = struct.Struct("<b")
_struct_f = struct.Struct("<f")
_struct_4d = struct.Struct("<4d")
_struct_2I = struct.Struct("<2I")
_struct_3d = struct.Struct("<3d")
"""autogenerated by genpy from task_planner/PlanTaskResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class PlanTaskResponse(genpy.Message):
  _md5sum = "ce5b451fa3baf09328c52bff9c283adf"
  _type = "task_planner/PlanTaskResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """string[] plans


"""
  __slots__ = ['plans']
  _slot_types = ['string[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       plans

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlanTaskResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.plans is None:
        self.plans = []
    else:
      self.plans = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.plans)
      buff.write(_struct_I.pack(length))
      for val1 in self.plans:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.pack('<I%ss'%length, length, val1))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.plans = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8')
        else:
          val1 = str[start:end]
        self.plans.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.plans)
      buff.write(_struct_I.pack(length))
      for val1 in self.plans:
        length = len(val1)
        if python3 or type(val1) == unicode:
          val1 = val1.encode('utf-8')
          length = len(val1)
        buff.write(struct.pack('<I%ss'%length, length, val1))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.plans = []
      for i in range(0, length):
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1 = str[start:end].decode('utf-8')
        else:
          val1 = str[start:end]
        self.plans.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
class PlanTask(object):
  _type          = 'task_planner/PlanTask'
  _md5sum = 'e14aed90eedaddbd0822c0e675600537'
  _request_class  = PlanTaskRequest
  _response_class = PlanTaskResponse
