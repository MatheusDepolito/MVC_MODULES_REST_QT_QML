pragma Singleton

import QtQuick 2.15
import QtCore

Item {
  id: root
  property alias themes: temas
  property var temaAtual: temas.temaDark

  Settings {
    category: "PaletaCores"
    property alias temaAtual: root.temaAtual
  }
  //9c9c9c texto
  QtObject {
    id: temas
    readonly property var temaLight: ["#f0f0f1", "#f9f8fa", "#67666c", "#e9e8e9", "#67666c", "#f1eef2", "#67666c", "#FF595E", "#FFCA3A", "#8AC926", "#1982C4", "#f9f8fa", "#EAEAF1", "#333333"]
    readonly property var temaDark: ["#121212", "#161616", "#fff", "#2c2c2c", "#fff", "#262626", "#fff", "#B73C41", "#B38724", "#4E7920", "#1C4E74", "#1e1e1e", "#15150E", "#fff"]
  }

  readonly property string colorBackground: temaAtual[0]
  readonly property string colorContainer: temaAtual[1]
  readonly property string colorText: temaAtual[2]
  readonly property string colorGridLine: temaAtual[3]
  readonly property string colorTextAxis: temaAtual[4]
  readonly property string colorBackgroundToolTip: temaAtual[5]
  readonly property string colorTextToolTip: temaAtual[6]

  readonly property string colorIrregular: temaAtual[7]
  readonly property string colorRegular: temaAtual[8]
  readonly property string colorBom: temaAtual[9]
  readonly property string colorMuitoBom: temaAtual[10]

  readonly property string colorBordaBarras: temaAtual[11]
  readonly property string colorShadow: temaAtual[12]
  readonly property string colorTitle: temaAtual[13]
}
