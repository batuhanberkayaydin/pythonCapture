import click as _click
import cv2
import base64
from io import BytesIO
import json
  
f = open('config.json')
data = json.load(f)
frame_width = int(data['width'])
frame_height = int(data['height'])
f.close()

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, frame_width)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, frame_height)
cap.set(cv2.CAP_PROP_FPS, 15)


def get_frames(image_name):

    # using click package to make sure that path is interpreted correctly
    _click.command()
    _click.argument('image_name',type=_click.Path(exists=True,
                                dir_okay=True, readable=True))
    
    retval, image = cap.read()

    retval, buffer = cv2.imencode('.jpg', image)
    jpg_as_text = base64.b64encode(buffer)

    return(jpg_as_text) 