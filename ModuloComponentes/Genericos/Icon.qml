import QtQuick 2.15

Item {
  id: root
  property alias pathImage: image.source
  Image {
    id: image
    sourceSize.height: root.height
    sourceSize.width: root.width
    fillMode: Image.PreserveAspectFit
  }
}
