// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QIcon>
#include <QMessageBox>
#include <QtConcurrent/QtConcurrentRun>
#include "citra_qt/configuration/configure_web.h"
#include "citra_qt/uisettings.h"
#include "core/telemetry_session.h"
#include "network/network_settings.h"
#include "ui_configure_web.h"

ConfigureWeb::ConfigureWeb(QWidget* parent)
    : QWidget(parent), ui(std::make_unique<Ui::ConfigureWeb>()) {
    ui->setupUi(this);
    connect(&verify_watcher, &QFutureWatcher<bool>::finished, this, &ConfigureWeb::OnLoginVerified);

#ifndef USE_DISCORD_PRESENCE
    ui->discord_group->setVisible(false);
#endif
    SetConfiguration();
}

ConfigureWeb::~ConfigureWeb() = default;

void ConfigureWeb::SetConfiguration() {
    ui->toggle_discordrpc->setChecked(UISettings::values.enable_discord_presence.GetValue());
}

void ConfigureWeb::ApplyConfiguration() {
}

void ConfigureWeb::RefreshTelemetryID() {
}

void ConfigureWeb::OnLoginChanged() {
}

void ConfigureWeb::VerifyLogin() {
}

void ConfigureWeb::OnLoginVerified() {
}

void ConfigureWeb::RetranslateUI() {
    ui->retranslateUi(this);
}

void ConfigureWeb::SetWebServiceConfigEnabled(bool enabled) {
}
