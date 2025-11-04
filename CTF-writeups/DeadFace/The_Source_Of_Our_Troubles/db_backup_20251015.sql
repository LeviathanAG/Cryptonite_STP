-- Night Vale University Database Backup
-- Date: 2025-10-15
-- VULNERABILITY: Exposed backup file (Moderate)
-- Flag: deadface{b4ckup_f1l3s_sh0uld_b3_s3cur3d}

-- Backup contains sensitive information that should not be publicly accessible
-- This file demonstrates the importance of proper backup security

-- Database credentials (should never be in backups!)
-- Host: db
-- Database: nvu_portal  
-- Username: nvu_user
-- Password: NightVale2023!

USE nvu_portal;

-- Hidden admin account for emergency access
INSERT INTO users (username, password, email, role) VALUES
('emergency_admin', MD5('EmergencyAccess2025!'), 'emergency@nvu.edu', 'admin');

-- Sensitive research notes
INSERT INTO research_projects (project_name, lead_researcher, classified, details, funding_amount) VALUES
('Project Nightfall', 'Dr. Unknown', 1, 'Classified research into anomalous phenomena. Contact: classified@nvu.edu', 10000000.00);

-- Additional hidden announcement
INSERT INTO announcements (title, content, author, is_hidden) VALUES
('Security Audit Required', 'Multiple vulnerabilities detected in portal system. Immediate action required.', 'Security Team', 1);

-- End of backup