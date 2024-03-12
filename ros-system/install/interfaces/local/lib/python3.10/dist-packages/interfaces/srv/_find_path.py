# generated from rosidl_generator_py/resource/_idl.py.em
# with input from interfaces:srv/FindPath.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'alpha'
# Member 'bta'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FindPath_Request(type):
    """Metaclass of message 'FindPath_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interfaces.srv.FindPath_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__find_path__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__find_path__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__find_path__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__find_path__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__find_path__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ALPHA__DEFAULT': numpy.array((10.0, 360.0, ), dtype=numpy.float64),
            'BTA__DEFAULT': numpy.array((500.0, 20.0, ), dtype=numpy.float64),
            'EPSILON__DEFAULT': 1.0,
            'BOXWIDTH__DEFAULT': 512.0,
            'BOXHEIGHT__DEFAULT': 512.0,
            'R0__DEFAULT': 30.0,
            'QTYPE__DEFAULT': 0,
            'SEED__DEFAULT': 111,
            'DELTAX__DEFAULT': 0.0,
            'DELTAY__DEFAULT': 0.0,
            'SCALE__DEFAULT': 1.0,
            'NUMPTS__DEFAULT': 12,
            'PTS__DEFAULT': '10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92',
            'NUMPOLYGONS__DEFAULT': 3,
            'POLYGONS__DEFAULT': '1,4,3,2,1|5,9,8,7,6,5|10,12,11,10',
        }

    @property
    def ALPHA__DEFAULT(cls):
        """Return default value for message field 'alpha'."""
        return numpy.array((10.0, 360.0, ), dtype=numpy.float64)

    @property
    def BTA__DEFAULT(cls):
        """Return default value for message field 'bta'."""
        return numpy.array((500.0, 20.0, ), dtype=numpy.float64)

    @property
    def EPSILON__DEFAULT(cls):
        """Return default value for message field 'epsilon'."""
        return 1.0

    @property
    def BOXWIDTH__DEFAULT(cls):
        """Return default value for message field 'boxwidth'."""
        return 512.0

    @property
    def BOXHEIGHT__DEFAULT(cls):
        """Return default value for message field 'boxheight'."""
        return 512.0

    @property
    def R0__DEFAULT(cls):
        """Return default value for message field 'r0'."""
        return 30.0

    @property
    def QTYPE__DEFAULT(cls):
        """Return default value for message field 'qtype'."""
        return 0

    @property
    def SEED__DEFAULT(cls):
        """Return default value for message field 'seed'."""
        return 111

    @property
    def DELTAX__DEFAULT(cls):
        """Return default value for message field 'deltax'."""
        return 0.0

    @property
    def DELTAY__DEFAULT(cls):
        """Return default value for message field 'deltay'."""
        return 0.0

    @property
    def SCALE__DEFAULT(cls):
        """Return default value for message field 'scale'."""
        return 1.0

    @property
    def NUMPTS__DEFAULT(cls):
        """Return default value for message field 'numpts'."""
        return 12

    @property
    def PTS__DEFAULT(cls):
        """Return default value for message field 'pts'."""
        return '10,502|110,502|110,402|10,402|200,312|250,332|300,292|210,162|220,202|50,112|100,162|150,92'

    @property
    def NUMPOLYGONS__DEFAULT(cls):
        """Return default value for message field 'numpolygons'."""
        return 3

    @property
    def POLYGONS__DEFAULT(cls):
        """Return default value for message field 'polygons'."""
        return '1,4,3,2,1|5,9,8,7,6,5|10,12,11,10'


class FindPath_Request(metaclass=Metaclass_FindPath_Request):
    """Message class 'FindPath_Request'."""

    __slots__ = [
        '_alpha',
        '_bta',
        '_epsilon',
        '_boxwidth',
        '_boxheight',
        '_r0',
        '_qtype',
        '_seed',
        '_deltax',
        '_deltay',
        '_scale',
        '_numpts',
        '_pts',
        '_numpolygons',
        '_polygons',
    ]

    _fields_and_field_types = {
        'alpha': 'double[2]',
        'bta': 'double[2]',
        'epsilon': 'double',
        'boxwidth': 'double',
        'boxheight': 'double',
        'r0': 'double',
        'qtype': 'int64',
        'seed': 'int64',
        'deltax': 'double',
        'deltay': 'double',
        'scale': 'double',
        'numpts': 'int64',
        'pts': 'string',
        'numpolygons': 'int64',
        'polygons': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.alpha = kwargs.get(
            'alpha', FindPath_Request.ALPHA__DEFAULT)
        self.bta = kwargs.get(
            'bta', FindPath_Request.BTA__DEFAULT)
        self.epsilon = kwargs.get(
            'epsilon', FindPath_Request.EPSILON__DEFAULT)
        self.boxwidth = kwargs.get(
            'boxwidth', FindPath_Request.BOXWIDTH__DEFAULT)
        self.boxheight = kwargs.get(
            'boxheight', FindPath_Request.BOXHEIGHT__DEFAULT)
        self.r0 = kwargs.get(
            'r0', FindPath_Request.R0__DEFAULT)
        self.qtype = kwargs.get(
            'qtype', FindPath_Request.QTYPE__DEFAULT)
        self.seed = kwargs.get(
            'seed', FindPath_Request.SEED__DEFAULT)
        self.deltax = kwargs.get(
            'deltax', FindPath_Request.DELTAX__DEFAULT)
        self.deltay = kwargs.get(
            'deltay', FindPath_Request.DELTAY__DEFAULT)
        self.scale = kwargs.get(
            'scale', FindPath_Request.SCALE__DEFAULT)
        self.numpts = kwargs.get(
            'numpts', FindPath_Request.NUMPTS__DEFAULT)
        self.pts = kwargs.get(
            'pts', FindPath_Request.PTS__DEFAULT)
        self.numpolygons = kwargs.get(
            'numpolygons', FindPath_Request.NUMPOLYGONS__DEFAULT)
        self.polygons = kwargs.get(
            'polygons', FindPath_Request.POLYGONS__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.alpha != other.alpha):
            return False
        if all(self.bta != other.bta):
            return False
        if self.epsilon != other.epsilon:
            return False
        if self.boxwidth != other.boxwidth:
            return False
        if self.boxheight != other.boxheight:
            return False
        if self.r0 != other.r0:
            return False
        if self.qtype != other.qtype:
            return False
        if self.seed != other.seed:
            return False
        if self.deltax != other.deltax:
            return False
        if self.deltay != other.deltay:
            return False
        if self.scale != other.scale:
            return False
        if self.numpts != other.numpts:
            return False
        if self.pts != other.pts:
            return False
        if self.numpolygons != other.numpolygons:
            return False
        if self.polygons != other.polygons:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def alpha(self):
        """Message field 'alpha'."""
        return self._alpha

    @alpha.setter
    def alpha(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'alpha' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 2, \
                "The 'alpha' numpy.ndarray() must have a size of 2"
            self._alpha = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'alpha' field must be a set or sequence with length 2 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._alpha = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def bta(self):
        """Message field 'bta'."""
        return self._bta

    @bta.setter
    def bta(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float64, \
                "The 'bta' numpy.ndarray() must have the dtype of 'numpy.float64'"
            assert value.size == 2, \
                "The 'bta' numpy.ndarray() must have a size of 2"
            self._bta = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'bta' field must be a set or sequence with length 2 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._bta = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def epsilon(self):
        """Message field 'epsilon'."""
        return self._epsilon

    @epsilon.setter
    def epsilon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'epsilon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'epsilon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._epsilon = value

    @builtins.property
    def boxwidth(self):
        """Message field 'boxwidth'."""
        return self._boxwidth

    @boxwidth.setter
    def boxwidth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'boxwidth' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'boxwidth' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._boxwidth = value

    @builtins.property
    def boxheight(self):
        """Message field 'boxheight'."""
        return self._boxheight

    @boxheight.setter
    def boxheight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'boxheight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'boxheight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._boxheight = value

    @builtins.property
    def r0(self):
        """Message field 'r0'."""
        return self._r0

    @r0.setter
    def r0(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'r0' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'r0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._r0 = value

    @builtins.property
    def qtype(self):
        """Message field 'qtype'."""
        return self._qtype

    @qtype.setter
    def qtype(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'qtype' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'qtype' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._qtype = value

    @builtins.property
    def seed(self):
        """Message field 'seed'."""
        return self._seed

    @seed.setter
    def seed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'seed' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'seed' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._seed = value

    @builtins.property
    def deltax(self):
        """Message field 'deltax'."""
        return self._deltax

    @deltax.setter
    def deltax(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'deltax' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'deltax' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._deltax = value

    @builtins.property
    def deltay(self):
        """Message field 'deltay'."""
        return self._deltay

    @deltay.setter
    def deltay(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'deltay' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'deltay' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._deltay = value

    @builtins.property
    def scale(self):
        """Message field 'scale'."""
        return self._scale

    @scale.setter
    def scale(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'scale' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'scale' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._scale = value

    @builtins.property
    def numpts(self):
        """Message field 'numpts'."""
        return self._numpts

    @numpts.setter
    def numpts(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'numpts' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'numpts' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._numpts = value

    @builtins.property
    def pts(self):
        """Message field 'pts'."""
        return self._pts

    @pts.setter
    def pts(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'pts' field must be of type 'str'"
        self._pts = value

    @builtins.property
    def numpolygons(self):
        """Message field 'numpolygons'."""
        return self._numpolygons

    @numpolygons.setter
    def numpolygons(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'numpolygons' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'numpolygons' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._numpolygons = value

    @builtins.property
    def polygons(self):
        """Message field 'polygons'."""
        return self._polygons

    @polygons.setter
    def polygons(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'polygons' field must be of type 'str'"
        self._polygons = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FindPath_Response(type):
    """Metaclass of message 'FindPath_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interfaces.srv.FindPath_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__find_path__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__find_path__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__find_path__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__find_path__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__find_path__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FindPath_Response(metaclass=Metaclass_FindPath_Response):
    """Message class 'FindPath_Response'."""

    __slots__ = [
        '_response',
        '_path',
        '_boxes',
    ]

    _fields_and_field_types = {
        'response': 'string',
        'path': 'string',
        'boxes': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.response = kwargs.get('response', str())
        self.path = kwargs.get('path', str())
        self.boxes = kwargs.get('boxes', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.response != other.response:
            return False
        if self.path != other.path:
            return False
        if self.boxes != other.boxes:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'response' field must be of type 'str'"
        self._response = value

    @builtins.property
    def path(self):
        """Message field 'path'."""
        return self._path

    @path.setter
    def path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'path' field must be of type 'str'"
        self._path = value

    @builtins.property
    def boxes(self):
        """Message field 'boxes'."""
        return self._boxes

    @boxes.setter
    def boxes(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'boxes' field must be of type 'str'"
        self._boxes = value


class Metaclass_FindPath(type):
    """Metaclass of service 'FindPath'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'interfaces.srv.FindPath')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__find_path

            from interfaces.srv import _find_path
            if _find_path.Metaclass_FindPath_Request._TYPE_SUPPORT is None:
                _find_path.Metaclass_FindPath_Request.__import_type_support__()
            if _find_path.Metaclass_FindPath_Response._TYPE_SUPPORT is None:
                _find_path.Metaclass_FindPath_Response.__import_type_support__()


class FindPath(metaclass=Metaclass_FindPath):
    from interfaces.srv._find_path import FindPath_Request as Request
    from interfaces.srv._find_path import FindPath_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
