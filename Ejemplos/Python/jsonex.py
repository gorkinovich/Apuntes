# Fichero: jsonex.py
import json

class ComplexEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, complex):
            return {'class': 'complex',
                    'real' : obj.real,
                    'imag' : obj.imag}
        else:
            return json.JSONEncoder.default(self, obj)

def complex_decoder(data):
    if 'class' in data and data['class'] == 'complex':
        return complex(data['real'], data['imag'])
    else:
        return data

def decode(victim):
    return json.loads(victim, object_hook=complex_decoder)

def encode(victim):
    return json.dumps(victim, cls=ComplexEncoder)

def test(victim):
    print(f"{victim    = }")
    to_json = encode(victim)
    print(f"{to_json   = }")
    from_json = decode(to_json)
    print(f"{from_json = }")
