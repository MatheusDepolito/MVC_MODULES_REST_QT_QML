import QtQuick
import QtQuick.Window
import QtQuick.Controls
import ModuloMatriculas 1.0
import ModuloConstantes 1.0

ApplicationWindow {
  id: root
  visibility: ApplicationWindow.Maximized
  visible: true
  title: Constantes.title

  Test {
    width: 100
    height: 100
  }
}
